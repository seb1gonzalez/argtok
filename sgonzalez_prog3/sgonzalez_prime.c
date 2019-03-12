// UT El Paso EE 4374 Assignment 3
// Multi-threaded Prime Number Search
// Author: ???
//
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "sgonzalez_prime.h"

/* Global variables that are shared */
sPRIME_THREAD primeThreadData[MAX_THREADS];
int	numThreads;

void *prime_search(void *param)
{
	/*For range values*/
	unsigned int start,end,current;
	start = param[2];
	end = param[3];
	for (unsigned int i = start; i < end; i++){
		param[1] = i;
		return test_prime(i);
	}

}

void *mini_shell(void *param)
{
	int inputSize, i;
	int threadNum;
	char buff[128];		// Character buffer

	while(1)
	{
		// Request a line of input
		write(1, " -> ", 4);
		// Read the line
		inputSize = read(0, buff, 128);
		// Strip off carriage return
		buff[inputSize-1] = '\0';
		
		if((buff[0] >= '1') && (buff[0] <= '9'))
		{
			// An integer was entered
			threadNum = buff[0] - '0';
			if(threadNum <= numThreads)
			{
				printf("Thread %d progress: %d\n", threadNum, primeThreadData[threadNum-1].current);
			}
			else
			{
				printf("Thread %d does not exist\n", threadNum);
			}
			
		}
		else
		{		
			if(buff[0] == 'a')
			{
				// Print status for all threads
				for(i = 0; i < numThreads; i++)
				{
					printf("Thread %d progress: %d\n", i+1, primeThreadData[i].current);
				}
			}
			else
			{
				printf("Unrecognized input\n");
			}
		}

		printf("\n");
		fflush(NULL);

	}

	pthread_exit(0);

}

int test_prime(int n)
{
	if(n>1){ // primes are bigger than 1
		if(n == 2){return 1;}
		if(n % 2 == 0){return 0;} // no evens allowed, except 2
		for(int i = 3; i < 13; i+=2){ // check if divisible by 3,5,7,9,11,13..when it's not the same number
			if(n % i == 0 && n!=i){return 0;}	
		}
		return 1;
	}
	else{
		return 0;
	}
}
