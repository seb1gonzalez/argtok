#include <stdio.h>
#include "sgonzalez_argtok.h"

//Returns the length of a string
int get_len(char* str){
  int size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}
// Returns amount of words in the input
int get_spaces(char* input){
  int spaces = 0;
  while (str[size] != '\0') {
    if (input[spaces] == ' ') {
      spaces++;
    }
  }
  return spaces+1;
}
}

/*
Allocates memory for strings in memory
Creates an array of pointers to saved strings
Returns Strings after allocation
*/

char **argtok(char* str){
  char **ptr[10];
  return *ptr;
}
