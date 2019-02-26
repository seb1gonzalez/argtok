#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//
//	EE 4374 Assignment # 2 Command Executer
//	Author: ???
//
int getLength(char** arr){
  int count = 0;
  int i = 0;
  while (arr[i] != NULL) {
    count++;
    i++;
  }
  return count;
}

int execBackground(char **args)
{
    int i;
    // check for the ampersand at the end of the set of tokens
    i = 0;
    while(args[i] != 0)
    {
         i++;
    }                       // traverse to the end of the tokens
    if(args[i-1][0] == '&') // check the last token
    {
        free(args[i-1]);
        args[i-1] = NULL;  // remove the ampersand
        return 1;
    }
    else
    {
        return 0;
    }
}

int executeCmd(char **args){
  for (size_t i = 0; i < getLength(args); i++) {
    if (args[i] == "ls") {
      printf("%s\n","You typed ls" );
    }
  }
  return 0;
}
