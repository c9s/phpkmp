--TEST--
kmp search with p
--FILE--
<?php
$needle = "abcab";
$prefix = kmp_prefix($needle);
$p = kmp_search_prefix("aabbccdd", $prefix);
var_dump($p);

$p = kmp_search_prefix("bbbaaaabcab", $prefix);
var_dump($p);
--EXPECT--
int(-1)
int(6)
