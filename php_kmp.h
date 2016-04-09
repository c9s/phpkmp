#ifndef _PHP_KMP_H
  #define _PHP_KMP_H
  #ifdef HAVE_CONFIG_H
  #include "config.h"
#endif
#ifdef ZTS
  #include <TSRM.h>
#endif

#include <php.h>

#define PHP_KMP_NAME "KMP"
#define PHP_KMP_VERSION "1.0.0"
#define PHP_KMP_PREFIX_RES_NAME "KMPPrefix"

ZEND_BEGIN_MODULE_GLOBALS(kmp)
  /* global variable here */
ZEND_END_MODULE_GLOBALS(kmp)

extern zend_module_entry kmp_module_entry;

PHP_MINIT_FUNCTION(kmp);
PHP_MSHUTDOWN_FUNCTION(kmp);
PHP_MINFO_FUNCTION(kmp);

PHP_FUNCTION(kmp_search);
PHP_FUNCTION(kmp_search_prefix);
PHP_FUNCTION(kmp_prefix);
#endif
