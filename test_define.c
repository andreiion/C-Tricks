#include <stdio.h>
#include <string.h>

#define STRING "00000000"
#define INT 0

int main ()
{
  int a;
  char str[20];

  a = INT;
  sscanf(STRING, "%s", str);
  //strncpy(str, STRING, 8);
  str[8] = 0;
  sscanf(INT, "%s", str);

  printf("int: %d\nstr:%s\n", a, str);



  return 0;
}
