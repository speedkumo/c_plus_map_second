#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
int main() {
  char str[] = "123, 456, 789";
  regex_t preg;
  size_t nmatch = 5;
  regmatch_t pmatch[nmatch];
  int i, j;

  if (regcomp(&preg, "([[:digit:]]+), ([[:digit:]]+), ([[:digit:]]+)", REG_EXTENDED|REG_NEWLINE) != 0) {
  printf("regex compile failed.\n");
  exit(1);
  }

  printf("String = %s\n", str);
 
  if (regexec(&preg, str, nmatch, pmatch, 0) != 0) {
  printf("No match.\n");
  } else {
  for (i = 0; i < nmatch; i++) { /* nmatch にマッチした件数が入る */
  printf("Match position = %d, %d , str = ", (int)pmatch[i].rm_so, (int)pmatch[i].rm_eo);
  if (pmatch[i].rm_so >= 0 && pmatch[i].rm_eo >= 0) {
  for (j = pmatch[i].rm_so ; j < pmatch[i].rm_eo; j++) {
  putchar(str[j]);
  }
  }
  printf("\n");
  }
  }

  regfree(&preg);
  return 0;

  }
