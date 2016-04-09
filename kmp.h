#ifndef KMP_H
#define KMP_H


/*
  P structure for storing prefix-suffix lengths.
 */
typedef struct {
  unsigned int * lengths;
  unsigned int size;
} P_;

typedef unsigned int PType;

/*
  Failure function

  This function pre-compute the prefix-suffix length in an array.

  @param str the haystack string.
  @param len the length of the haystack string.
  @return the position of the needle in the haystack string.
*/
void F(const char *str, unsigned int len, PType P[]);

/**
  The main KMP string search function.
  
  This function always compute the P for each call.
  
  @param search the haystack string.
  @param search_len the length of the haystack string.
  @param needle     the needle string
  @param needle_len the length of the needle string.
  @return The position of needle in haystack string.
*/
int kmp_search(
  const char *search,
  const int search_len,
  const char *needle,
  const int needle_len);


/**
  KMP string search with pre-computed P array.
  
  This function provides an extra parameter for passing precomputed P.
  
  @param search the haystack string.
  @param search_len the length of the haystack string.
  @param needle     the needle string
  @param needle_len the length of the needle string.
  @param P          the pre-computed P array.
  @return The position of needle in haystack string.
*/
int kmp_search_p(
  const char *search,
  const int search_len,
  const char *needle,
  const int needle_len,
  PType P[]);


/**
  KMP string search but printing the debugging steps.
  
  @param search the haystack string.
  @param search_len the length of the haystack string.
  @param needle     the needle string
  @param needle_len the length of the needle string.
  @return The position of needle in haystack string.
*/
int kmp_search_debug(
  const char *search,
  const int search_len,
  const char *needle,
  const int needle_len);


#endif
