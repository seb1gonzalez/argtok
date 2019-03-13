// UT El Paso EE 4374 Assignment 3
// Multi-threaded Prime Number Search
// Author: Sebastian Gonzalez... and Dr. Michael McGarry
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
	char primeFiles[2][15];// 2 files with filename length of 15 chars
	FILE *primesx; // create a file pointer
	/*For range values*/
	unsigned int start,end,current;
	start = ((sPRIME_THREAD *)param)->low;
	end = ((sPRIME_THREAD *)param)->high;
	int num = ((sPRIME_THREAD *)param)->num;// num is either 1 or 2
	sprintf(primeFiles[num-1], "primes%d", num); //num - 1 because array indexing
	primesx = fopen(primeFiles[num-1],"w");//create the file
	for (unsigned int i = start; i <= end; i++){
		((sPRIME_THREAD *)param)->current = i;
		if(test_prime(i)){ // okay we have a winner
 			fprintf(primesx, "%d\n",i);//insert our prime number
 		}
	}
fclose(primesx);
}
/*
 THIS CODE GENERATES A SEGMENTATION FAULT AND CREATES A FILE NAMED 1...
 file creation is not correct...try another approach..maybe an array of files??
void *prime_search(void *param)
{
	FILE *primesx; // create a file pointer
	unsigned int start,end,current;
	start = ((sPRIME_THREAD *)param)->low;
	end = ((sPRIME_THREAD *)param)->high;
	for (unsigned int i = start; i < end; i++){
		((sPRIME_THREAD *)param)->current = i;
		if(test_prime(i)){ // okay we have a winner
 			char filename[15]; //for our filename with int concatenation at the end
       unsigned int num = ((sPRIME_THREAD *)param)->num;
       sprintf(filename, "%d", num); //filename+int
 			 primesx = fopen(filename,"w");//create the file
 			fprintf(primesx, "%d\n",i);//insert our prime number
 		}
	}
fclose(primesx);
}
*/
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
