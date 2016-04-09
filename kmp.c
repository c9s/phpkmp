/**
 * KMP string search algorithm implementation.
 *
 * @author Yo-An Lin
 * @copyright Yo-An Lin
 */
#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"


/*
    Failure function

    This function pre-compute the prefix-suffix length in an array.

    @param str the haystack string.
    @param len the length of the haystack string.
    @return the position of the needle in the haystack string.
*/
void F(const char *str, unsigned int len, char P[]) {
    unsigned int i = 1;
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
        char P[])
{
    unsigned int j = 0;
    for (unsigned int i = 0; i < search_len ; i++) {
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
        const int needle_len)
{
    char P[needle_len];
    F(needle, needle_len, P);
    return kmp_search_p(search, search_len, needle, needle_len, P);
}


