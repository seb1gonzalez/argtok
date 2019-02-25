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
void split_str(char* input, int length ){
  int i = 0;
    for(int i = 0; i < length; i++){
    if (input[i] == ' '){
      input[i] = '\0';
    }
  }
}
//Counts total words given the '\0' character
int count_words(char* str, int length){
  int count = 0;
  if(length > 0){count++;}
  for(int i = 0; i < length; i++){
    if (str[i] == '\0'){
      count++;
    }
  }
  return count;
}

// Returns the address of the array of pointers after allocation

char **argtok(char* str){
  int length = get_len(str);
   //insert '\0' in blank spaces
  split_str(str,length);
  //create array of pointers
  char **mem = (char**)calloc(count_words(str, length) +1,sizeof(char*));
  mem[count_words(str, length)] = NULL;

  //counter for words in input
  int word_count = 0;
  word_count = count_words(str,length);

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
    for (int i = 0; i < length; i++)
    {
      if (str[i] != '\0')
      {
        count++;
        arr[index] = count;
      }
      else{
        arr[index] = count;
        count = 0;
        index++;
      }
    }

    //given the size of each word, allocate space for each word
    // note: each size of each word is stored in array "arr"
    char* myString  = (char*)calloc(arr[x],sizeof(char));

    //now populate the created array with the actual word
    for (int i = 0; i < arr[x]; ++i)
    {
      myString[i] = str[start_index+i];
    }
    // set start index = size of current word + 2 
    // h e l l o \0 w o r l  d \0
    // 1 2 3 4 5 6  7 8 9 10 11 12
    // 5 + 2 = 7 ; 7 is the starting index of next word
    start_index = arr[x] + 1 ;
    //save myString in pointer array
    mem[x] = myString;

    //increment word counter
    x++;
  }
  
  //some black magic is happenning here!...
  //segmentation faul occurs when we run 'til count words +1
  for (int i = 0; i < count_words(str,length)+1 ;i++)
  {
   //printf("value of i: %i\n",i);
   printf("Index: %i %s\n",i,mem[i]);
  }
  //printf("%s\n",mem[0]);
 // printf("%s\n",mem[1]);
  //printf(" %s\n",mem[count_words(str, length)]);

  return mem;
}
