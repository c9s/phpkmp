#ifndef KMP_H
#define KMP_H

/**
 * basic kmp string search
 */
int kmp_search(
        const char *search,
        const int search_len,
        const char *needle,
        const int needle_len);


/**
 * kmp string search with pre-computed P
 */
int kmp_search_p(
        const char *search,
        const int search_len,
        const char *needle,
        const int needle_len,
        char P[]);


/**
 * kmp string search with debug message.
 */
int kmp_search_debug(
        const char *search,
        const int search_len,
        const char *needle,
        const int needle_len);


#endif
