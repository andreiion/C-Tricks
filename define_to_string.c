#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//convert a define to a string

#define STR(x)      #x
#define XSTR(x)     STR(x)

#define MAX_SIZE 12345

int main()
{

  printf("string %s\n", XSTR(MAX_SIZE));

  return 0;
}
