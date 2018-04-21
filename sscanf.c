#include <string.h>
#include <stdio.h>

int main()
{
  char str[] = "\"172.0.0.1\"";
  char *poz;
  char new_str[25];

  sscanf(str, "\"%[^\"]", new_str);


  printf("%s\n", new_str);

  return 0;
}
