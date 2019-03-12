#include <stdio.h>
#include <stdlib.h>
#include "sgonzalez_argtok.h"
int  main() {

	char input[255];
	prompt();
    fgets(input,255,stdin);

	//call to argtok
	char** my_mem = argtok(input);
	
	free(my_mem);


  return 0;
}
