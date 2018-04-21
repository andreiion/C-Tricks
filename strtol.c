#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char str[] = "1231512";
  char *poz;
  char new_str[25];
  long int a;

  a = strtol(str, NULL, 10);


  printf("%ld\n", a);

  return 0;
}
