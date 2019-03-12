#include <stdio.h>


void splitString(char* x){
  int i = 0;
while(x[i] != '\0'){
  if (x[i] == ' ') {
    printf("%s\n","I found a space");
  }
  i++;
}

}

int main()
{

  char str1[] = "Hello World";
  splitString(str1);

   return 0;
}
