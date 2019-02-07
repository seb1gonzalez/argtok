#include <stdio.h>
#include "sgonzalez_argtok.h"

char **argtok(char*){
  char str1[] = "";
  int *ptr_str1 = &str1;

  char str2[] = "";
  int *ptr_str2 = &str2;

  char **ptr_ptrs_strings[] = {};

  ptr_ptrs_strings[0] = ptr_str1;
  ptr_ptrs_strings[1] = ptr_str2;

  return ptr_ptrs_strings;
}
