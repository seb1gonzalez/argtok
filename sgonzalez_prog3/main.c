#include <stdio.h>
#include "sgonzalez_prime.h"
int main(){
for (int i = 0; i < 100; ++i)
{
	if(test_prime(i)){
		printf("%d\n",i);
	}
}
	return 0;
}