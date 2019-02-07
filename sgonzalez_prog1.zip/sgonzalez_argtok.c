#include <stdio.h>
#include <stdlib.h>
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
//There is a space between 2 words, so count all spaces
//Add one at the end and you get a count of all words
int get_total_words(char* input){
  int spaces = 0;
  while (input[spaces] != '\0') {
    if (input[spaces] == ' ') {
      spaces++;
    }
  }
  return spaces+1;
}
/*
Allocates memory for strings
Creates an array of pointers to save strings
Returns the address of the array of pointers after allocation

*/
char **argtok(char* str){
  int *mem = calloc(get_total_words(str) +1,sizeof(int));
  char **ptr_arr[get_total_words(str)];
  int *ptr_tomem = &mem;
  char i = 0;

  int start, end;//keep
  start = end = 0;
  while(str[i] != '\0'){
    if (str[i] == ' ') {
      end = i;
      char *word_found = malloc(end - start) +1);
      for (int j = 0; j < (end - start); j++) {
        word_found[j] = str[start];
      }
      word_found[end] = '\0';
      start = end
    }
    ptr_arr[i] = word_found;
    i++;
  }

  return ptr_arr;
}
