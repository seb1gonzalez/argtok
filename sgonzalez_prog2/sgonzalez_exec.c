#include <sys/types.h>
#include <sys/wait.h>       // for wait() function
#include <unistd.h>         // UNIX system call library: fork(), getpid(), etc.
#include <signal.h>         // Signal handler library
#include <stdio.h>          // Standard I/O library
#include <fcntl.h>
#include <stdlib.h>
//
//	EE 4374 Assignment # 2 Command Executer
//	Author: ???
//
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
//step by step
/*
1 Fork
2 check pid
3 execvp
4 check if command is possible
5 determine if background or not
6 free
7 return
*/

					/*STEPS*/
  int pid, exec, background;
  pid = fork(); 			//1
  background = execBackground(args);
  if(pid < 0){
    printf("ERROR, ugh");
    return -1;
  }
  else if (pid == 0){
  exec = execvp(args[0],args);		// 2
  printf("\n");
  if(exec < 0 && background == 0){	// 3
    printf("%s\n","Try another command" );
    }
  }
  if(background > 0){			// 4
    printf("\n");
    free(args);				// 5
    return 0;				// 6
  }
//not in background, wait
  wait(&exec);
  free(args);				//5
  return 0;				//6
}
