#include <stdio.h>
#include "sgonzalez_argtok.h"
int  main() {
  char str[] = "Hello there";
  int size = get_len(str);
  printf("The size of the string is: %d",size);
  printf("\n");
  return 0;
}
