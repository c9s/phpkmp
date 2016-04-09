<?php
/**
 * Implementation of the Knuth-Morris-Pratt Algorithm
 *
 * @copyright   Copyright (c) 2016, Yo-An Lin <yoanlin93@gmail.com>
 * @license     MIT
 */

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

function kmp_match($T, $P) {
    $array = array();
    $n = strlen($T);
    $m = strlen($P);
    $pi = kmp_compute_prefix($P);
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
            $array[] = $i - $m + 1;
            $l = $i;
            $q = $pi[$q];
        }
    }
    return $array;
}

/*
$matches = kmp_match($T, $P);
*/
$matches = kmp_match('abcdejdijdwojd', 'jdijd');
var_dump($matches);
