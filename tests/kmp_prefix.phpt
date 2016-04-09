--TEST--
kmp prefix test
--FILE--
<?php
$P = kmp_prefix("abcab");
var_dump(is_resource($P));
--EXPECT--
bool(true)
