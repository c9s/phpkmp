<?php
/**
 * Implementation of the Knuth-Morris-Pratt Algorithm
 *
 * @copyright   Copyright (c) 2016, Yo-An Lin <yoanlin93@gmail.com>
 * @license     MIT
 */

class KMPPrefix {
    public $P;
    public $str;
    public $len;
}


function kmp_compute_prefix($P) {
    $m = strlen($P);
    $pi = array();
    $pi[1] = 0;
    $k = 0;
    for ($q = 1; $q < $m; $q++) {
        while ($k > 0 && $P[$k] != $P[$q]) {
            $k = $pi[$k];
        }
        if ($P[$k] == $P[$q]) {
            $k++;
        }
        $pi[$q+1] = $k;
    }
    return $pi;
}

function kmp_search_prefix($T, KMPPrefix $prefix)
{
    $matches = array();
    $P = $prefix->str;
    $m = $prefix->len;
    $pi = $prefix->P;
    $n = strlen($T);
    $q = 0;
    $l = 0;
    for ($i = 0; $i < $n; $i++) {
        while ($q > 0 && $P[$q] != $T[$i]) {
            $q = $pi[$q];
        }
        if ($P[$q] == $T[$i]) {
            $q = $q + 1;
        }
        if ($q == $m) {
            $matches[] = $i - $m + 1;
            $l = $i;
            $q = $pi[$q];
        }
    }
    return $matches;
}

function kmp_search($T, $P) {
    $prefix = new KMPPrefix;
    $prefix->P = kmp_compute_prefix($P);
    $prefix->str = $P;
    $prefix->len = strlen($P);
    return kmp_search_prefix($T, $prefix);
}

/*
$matches = kmp_search($T, $P);
$matches = kmp_search('abcdejdijdwojd', 'jdijd');
var_dump($matches);
*/
