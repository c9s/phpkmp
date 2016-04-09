/**
 * KMP string search algorithm implementation.
 *
 * @author Yo-An Lin
 * @copyright Yo-An Lin
 */
#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"

KMPPrefix * kmp_prefix_new(const char *needle, uint32_t len)
{
  KMPPrefix *prefix = malloc(sizeof(KMPPrefix));
  prefix->P = calloc(sizeof(uint32_t), len);
  prefix->str = needle;
  prefix->len = len;
  return prefix;
}




void F(const char *str, uint32_t len, KMPPrefix *prefix) {
  uint32_t *P = prefix->P;
  uint32_t i = 1;
  int j = P[0] = 0; // longest prefix length
  P[1] = 0;
  for (; i < len ; i++) {
    while (j > 0 && str[i] != str[j]) {
      j = P[j-1];
    }
    if (str[i] == str[j]) {
      j++;
    }
    P[i] = j;
  }
}


int kmp_search_prefix(
  const char *search,
  const int search_len,
  KMPPrefix *prefix)
{
  const char *needle = prefix->str;
  const int needle_len = prefix->len;


  uint32_t *P = prefix->P;
  uint32_t j = 0;
  for (uint32_t i = 0; i < search_len ; i++) {
    while (j > 0 && search[i] != needle[j]) {
      j = P[j+1];
    }
    if (needle[j] == search[i]) {
      j++;
    }
    if (j == needle_len) {
      return i - needle_len + 1;
    }
  }
  return -1;
}

int kmp_search(
  const char *search,
  const int search_len,
  const char *needle,
  const int needle_len)
{
  uint32_t P[needle_len];
  KMPPrefix prefix;
  prefix.P = P;
  prefix.str = needle;
  prefix.len = needle_len;
  F(needle, needle_len, &prefix);
  return kmp_search_prefix(search, search_len, &prefix);
}
