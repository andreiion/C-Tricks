#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_array_string(char *str, char *array, int *size)
{
  char *p;
  int i = 0;
  p = strtok(str, ",");

  while (p != NULL) {

    strncpy((array + i), p, 1);
    *(array + i + 1) = 0;
    //memcpy(array[i++], p, 1);
    //printf("%s\n", array + i - 1);
    i++;
    p = strtok(NULL, ",");
  }
  *size = i;
}

int main ()
{
  //char str[] = ",,,,,,,,,,,,,ana,,are,mere,1,,2,,,,,,,,";
  //char str[] = ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
  char str[] = ",,a,b,c,d,e,f,,h,,j,,l,,";
  //char str[] = ",,,";
  char no_value_symbol = '?';
  char new_str[1024];
  char array_str[512][64];
  int size = strlen(str);
  int i;

  memset(new_str, 0, 1024);

  int new_char_poz = 0;
  for (i = 0; i < size; ++i)
  {
    if (size == 1 && str[i] == ',') //special case, size == 1
    {
      new_str[i + new_char_poz++] = no_value_symbol;
      new_str[i + new_char_poz++] = str[i];
      new_str[i + new_char_poz] = no_value_symbol;
    }
    else if (size == 1 && str[i] != ',')
    {
      new_str[i + new_char_poz] = str[i];
    }
    else if (size == 2 && i != 1)
    {
      if (str[i] == ',' && str[i + 1] == ',') ///< first element is missing
      {
        new_str[i + new_char_poz] = no_value_symbol;
        new_char_poz++;
        new_str[i + new_char_poz] = str[i];
        new_char_poz++;
        new_str[i + new_char_poz] = no_value_symbol;
        new_str[i + new_char_poz + 1] = str[i + 1];
        new_char_poz++;
        new_str[i + new_char_poz + 1] = no_value_symbol;
      }
      if (str[i] == ',' && str[i + 1] != ',')
      {
        new_str[i + new_char_poz++] = no_value_symbol;
        new_str[i + new_char_poz] = str[i];
        new_str[i + ++new_char_poz] = str[i + 1];
      }
      if (str[i] != ',' && str[i + 1] == ',')
      {
        new_str[i + new_char_poz] = str[i];
        new_str[i + ++new_char_poz] = str[i + 1];
        new_str[i + new_char_poz + 1] = no_value_symbol;
      }
      if (str[i] != ',' && str[i + 1] != ',')
      {
        new_str[i + new_char_poz] = str[i];
        new_str[i + new_char_poz + 1] = str[i + 1];
      }
    }
    else
    {
      if (str[i] == ',')
      {
        if (i == 0)
        {
          new_str[i + new_char_poz++] = no_value_symbol;
          new_str[i + new_char_poz] = str[i];
        }
        if (i == size - 1)
        {
          new_str[i + new_char_poz] = str[i];
          new_str[i + ++new_char_poz] = no_value_symbol;
        }
        if (str[i + 1] == ',')
        {
          new_str[i + new_char_poz] = str[i];
          new_str[i + ++new_char_poz] = no_value_symbol;
          new_str[i + new_char_poz + 1] = str[i + 1];
        }
        else if (i != size - 1)
        {
          new_str[i + new_char_poz] = str[i];
        }
      }
      if (str[i] != ',')
      {
        new_str[i + new_char_poz] = str[i];
      }
    }
  }
  printf("str: %s\n", str);
  printf("new_str: %s\n", new_str);

  create_array_string(new_str, (char *)array_str, &size);

  for (i = 0; i < size; ++i)
  {
    printf("%s\n", array_str[i]);
  }
}
