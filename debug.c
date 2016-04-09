#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "kmp.h"

static void printf_pad(int p, char *format, ...) {
  for (int i = 0 ; i < p; i++) {
    printf(" ");
  }
  va_list ap;
  va_start(ap, format);
  vprintf(format, ap);
  va_end(ap);
}


static void debug_match(const char *str, int i, int j)
{
  printf("--------\n");
  printf("%s\n", str);
  // printf_pad(i, "^\n");
  printf_pad(i-j,"%s\n", str);
  printf_pad(i-j+j, "^\n");
}


/**
 * failure function
 *
 * @param str the string
 * @param len length of the string
 */
void F_debug(const char *str, uint32_t len, KMPPrefix *prefix) {
  uint32_t i = 1;
  uint32_t * P = prefix->prefixes;
  int j = P[0] = 0; // longest prefix length
  P[1] = 0;
  for (; i < len ; i++) {
    printf("==================\n");
    printf("i=%d j=%d\n",i, j);
    debug_match(str, i, j);

    printf("if j > 0 && str[i] != str[j]\n");
    while (j > 0 && str[i] != str[j]) {
      printf("str[i] != str[j]\n");
      j = P[j-1];
      printf("j = P[j-1] => %d\n",j);
      debug_match(str, i, j);
    }
    printf("if str[i] == str[j]\n");
    if (str[i] == str[j]) {
      printf("str[i] == str[j]\n");
      j++;
      printf("j++ => %d\n",j);
    }
    printf("P[i] = j => %d\n", j);
    P[i] = j;

    printf("i++ => %d\n", i);
  }
}


int kmp_search_debug(
  const char *search,
  const int search_len,
  const char *needle,
  const int needle_len)
{
  printf("Search '%s' in '%s'\n", needle, search);
  int p = kmp_search(search, search_len, needle, needle_len);

  if (p > -1) {
    printf("Found pattern!\n");
    printf("%s\n", search);
    printf_pad(p, "^\n");
    printf_pad(p, "%s\n", needle);
    printf("pattern found at %d\n\n", p);
  } else {
    printf("Patter not found.\n\n");
  }
  return p;
}
