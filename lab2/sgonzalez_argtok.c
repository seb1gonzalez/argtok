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
//inserts sizes of words found in string // USE AFTER split_str()
void markSizes(char* str, int* arr, int length){
  int word_size = 0;
  int word_index = 0;;
  for (int i = 0; i < length; i++){
    if(str[i] != '\0'){
      word_size++;
      arr[word_index] = word_size;
    }
    else if(str[i] == '\0'){
      word_size = 0;
      word_index++;
    }

  }//end FOR loop

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
  //get the actual current length of full string
  int length = get_len(str);

   //insert '\0' in blank spaces
  split_str(str,length);

  //create array of pointers
  char **mem = (char**)calloc(count_words(str, length) +1,sizeof(char*));
  mem[count_words(str, length)] = NULL;

  //counter for words in input
  int word_count = 0;
  word_count = count_words(str,length);


  int x = 0;//to control while loop; also used as index for pointer array "mem"

  //array to keep track of size of each word in input
  int arr[word_count];
  int index = 0;

  //start_at to know from which index start inserting new word into created arrays with malloc
  int start_index = 0;

  while(x < word_count){ //for every word..

    //get length of all words stored in array
    markSizes(str,arr,length);


    //given the size of each word, allocate space for each word
    // note: each size of each word is stored in array "arr"
    char* myString  = (char*)calloc(arr[x],sizeof(char));

    //now populate the created array with the actual word
    for (int i = 0; i < arr[x]; i++)
    {
      if (str[start_index] == '\n')// ignore the enter key after getting the input
      {
        break;
      }

      myString[i] = str[start_index];
      start_index++;
    }
    //start index++ again to skip the \0 character between each word
    start_index++;
    //save myString in pointer array
    mem[x] = myString;

    //increment word counter
    x++;
  }//end While loop

//  for (int i = 0; i < count_words(str,length)+1 ;i++){
  //  printf("> %s\n",mem[i]);
  //}

  return mem;
}


//prompt to get the input string from a user
void prompt(){
  printf("%s","$ " );
}
