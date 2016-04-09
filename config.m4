PHP_ARG_ENABLE(kmp, whether to enable kmp extension support, 
  [--enable-kmp Enable kmp extension support])

CFLAGS="-std=c99"
if test $PHP_KMP != "no"; then
    PHP_NEW_EXTENSION(kmp, debug.c kmp.c php_kmp.c, $ext_shared)
fi
