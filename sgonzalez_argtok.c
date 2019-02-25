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
// Replaces an empty space with '\0'
void split_str(char* input){
  int i = 0;
  for(int i = 0; i < get_len(input); i++){
    if (input[i] == ' '){
      input[i] = '\0';
    }
  }
}
//Counts total words given the '\0' character
int count_words(char* str){
  int count = 0;
  for(int i = 0; i < get_len(input); i++){
    if (input[i] == '\0'){
      count++;
    }
  }
  return count;
}




// Returns the address of the array of pointers after allocation

char **argtok(char* str){
  //create array of pointers
  char *mem = (char*)calloc(get_total_words(str) +1,sizeof(char));
  //insert '\0' in blank spaces
  split_str(str);
  //counter for words in input
  int word_count = 0;
  word_count = count_words(str);

  //loop to allocate memory for found words & store words in pointer array
  int x = 0;//to control indexing of word count

  //array to keep track of size of each word in input
  int arr[word_count];
  int index = 0;

  //start_at to know from which index start inserting new word into created arrays with malloc
  int start_index = 0;

  while(x < word_count){ //for every word..
    //count to keep track of words
    int count = 0;
    for (int i = 0; i < get_len(str); ++i)
    {
      if (str[i] != '\0')
      {
        count++;
      }
      else{
        arr[index] = count;
        count = 0;
        index++;
      }
    }

    //given the size of each word, allocate space for each word
    // note: each size of each word is stored in array "arr"
    char* myString  = (char*)malloc(arr[word_count]);

    //now populate the created array with the actual word
    for (int i = 0; i < get_len(myString); ++i)
    {
      myString[i] = str[start_index];
    }
    // set start index = size of current word + 2 
    // h e l l o \0 w o r l  d \0
    // 1 2 3 4 5 6  7 8 9 10 11 12
    // 5 + 2 = 7 ; 7 is the starting index of next word
    start_index = arr[word_count] + 2 ;

    //save myString in pointer array
    mem[word_count] = myString;

    //increment word counter
    word_count++;
  }
  mem[get_len(mem) - 1] = NULL;
  return mem;
}
