#include <stdio.h>
#include "sgonzalez_prime.h"
int main(){
	unsigned int[2] range1,range2,range3,range4,range5;
	range1[0] = 1; range1[1] = 2500000;
	range2[0] = 2500001; range2[1] = 5000000;
	

	/*Setup for the first thread*/
	primeThreadData[0]->num = 1; //thread num
	primeThreadData[0]->current = 0;
	primeThreadData[0]->low = range1[0];
	primeThreadData[0]->high = range1[1];

	
	//thread(primesearch primeThreadData[0])
	//thread(primesearch primeThreadData[1])
	//thread(mini_shell(primeThreadData))


	return 0;
}