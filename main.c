#include <stdio.h>
#include <stdlib.h>
#include "sgonzalez_argtok.h"
int  main() {

	char word[] = "Hello World";
	//call to argtok
	char** my_mem = argtok(word);
	
	free(my_mem);

  return 0;
}
