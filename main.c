#include "kmp.h"
#define STRLS(str) str, (sizeof(str)-1)

int main()
{
  kmp_search_debug(STRLS("aabzabzabcz"), STRLS("aabaac"));

  kmp_search_debug(STRLS("aabzabzabcz"), STRLS("abc"));

  kmp_search_debug(STRLS("aabzabzabcz"), STRLS("abz"));
  // F(STRLS("aaabcqzabcqz"));
  return 0;
}
