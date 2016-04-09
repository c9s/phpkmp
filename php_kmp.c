#include "php_kmp.h"
#include "kmp.h"

#if COMPILE_DL_KMP
ZEND_GET_MODULE(kmp)
#endif


int le_kmp_prefix;
int le_kmp_prefix_persist;

ZEND_DECLARE_MODULE_GLOBALS(kmp)


ZEND_BEGIN_ARG_INFO_EX(arginfo_kmp_search, 0, 0, 2)
  ZEND_ARG_INFO(0, haystack)
  ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kmp_prefix, 0, 0, 1)
  ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_kmp_search_prefix, 0, 0, 2)
  ZEND_ARG_INFO(0, needle)
  ZEND_ARG_INFO(0, prefi)
ZEND_END_ARG_INFO()

static const zend_function_entry kmp_functions[] = {
  PHP_FE(kmp_search, arginfo_kmp_search)
  PHP_FE(kmp_search_prefix, arginfo_kmp_prefix)
  PHP_FE(kmp_prefix, arginfo_kmp_search_prefix)
  PHP_FE_END
};

static void php_kmp_prefix_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
  KMPPrefix *prefix = (KMPPrefix*)rsrc->ptr;
  if (prefix) {
    efree(prefix->P);
    efree(prefix);
  }
}

static void php_kmp_prefix_persist_dtor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
  KMPPrefix *prefix = (KMPPrefix*)rsrc->ptr;
  if (prefix) {
    pefree(prefix->P, 1);
    pefree(prefix, 1);
  }
}



zend_module_entry kmp_module_entry = {
  STANDARD_MODULE_HEADER,
  "KMP", // your extension name
  kmp_functions, // where you define your functions
  PHP_MINIT(kmp),
  PHP_MSHUTDOWN(kmp),
  NULL, // PHP_RINIT(kmp)
  NULL, // PHP_RSHUTDOWN(kmp)
  PHP_MINFO(kmp),
  "0.1",
  STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(kmp) {
  le_kmp_prefix = zend_register_list_destructors_ex(php_kmp_prefix_dtor, NULL, PHP_KMP_PREFIX_RES_NAME, module_number);
  le_kmp_prefix_persist = zend_register_list_destructors_ex(NULL, php_kmp_prefix_persist_dtor, PHP_KMP_PREFIX_RES_NAME, module_number);
  return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(kmp) {
  return SUCCESS;
}

PHP_MINFO_FUNCTION(kmp) {
}


/*
kmp_prefix pre-compute the prefix-suffix array and return the prefix array in
resource entry.
*/
PHP_FUNCTION(kmp_prefix) {
  char *needle;
  int len;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s",
      &needle, &len) == FAILURE)
  {
      RETURN_FALSE;
  }

  KMPPrefix *prefix = emalloc(sizeof(KMPPrefix));
  prefix->P = ecalloc(len, sizeof(uint32_t));
  prefix->str = zend_strndup(needle, len);
  prefix->len = len;
  F(needle, len, prefix);

  // This register the resource with the type (le_kmp_prefix) 
  // The type is related to the dtor function for freeing the resource.
  ZEND_REGISTER_RESOURCE(return_value, prefix, le_kmp_prefix);
}


PHP_FUNCTION(kmp_search_prefix) {
  char *haystack;
  int haystack_len;

  KMPPrefix *prefix;
  zval *zprefix;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sr",
        &haystack, &haystack_len, &zprefix) == FAILURE) {
    RETURN_FALSE;
  }

  // This will convert zval (zprefix) to prefix (PType*)
  // Default id is -1
  ZEND_FETCH_RESOURCE2(prefix, KMPPrefix*, &zprefix, -1,
      PHP_KMP_PREFIX_RES_NAME,
      le_kmp_prefix,
      le_kmp_prefix_persist);

  int p = kmp_search_prefix(haystack, haystack_len, prefix);
  RETURN_LONG(p);
}

PHP_FUNCTION(kmp_search) {
    char *haystack;
    int haystack_len;

    char *needle;
    int needle_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
            &haystack, &haystack_len, &needle, &needle_len) == FAILURE) {
        RETURN_FALSE;
    }
    int p = kmp_search(haystack, haystack_len, needle, needle_len);
    RETURN_LONG(p);
}


