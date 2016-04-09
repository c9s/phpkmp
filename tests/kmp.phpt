--TEST--
kmp search test
--FILE--
<?php
$p = kmp_search("abcabcdd","cdd");
var_dump($p);
--EXPECT--
int(5)
