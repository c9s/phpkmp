--TEST--
kmp search with p
--FILE--
<?php
$needle = "abcab";
$prefix = kmp_prefix($needle);
$p = kmp_search_p("aabbccdd", $needle, $prefix);
var_dump($p);

$p = kmp_search_p("bbbaaaabcab", $needle, $prefix);
var_dump($p);
--EXPECT--
int(-1)
int(6)
