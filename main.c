#include <stdio.h>
#include <stdlib.h>
#include "sgonzalez_argtok.h"
int  main() {
	char str[] = "Hello World";
	split_str(str);//  in place splitting
	printf("%s\n",str);

  return 0;
}
