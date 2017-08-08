/*
	UNIX Program to find FACTORIAL of a number given by parent process to child process, using fork()
	wait() is not used here.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

double fibo(int n) {		//	simple recursive fibonacci function with less lines of codes and less variables
	if(n <= 1)
		return n;
	else
		return (fibo(n-1) + fibo(n-2));
} 

int childProcess(int n) {		//get 'n' as parameter
	int i;
	
	printf("CHILD PID: %d\n", getpid());

	//	fibonacci series
	for(i=0; i<n; i++)
		printf("%lg\n", fibo(i));
}

// MAIN function
int main()
{
	pid_t pid;
	int n;

	printf("Parent PID:\t%d\n", getpid());	// PID of the Parent Process

	//	parent process.	main is the parent process that 
	printf("Enter the number of fibobacci terms to be shown upto...\n");		//	get value of N from parent (main function) to pass it to child
	scanf("%d", &n);
	
	pid = fork();		// fork a child

	if(pid < 0) {
		printf("Error! Child Not created!\n");
	}
	else if(pid == 0)
		childProcess(n);		// pass 'n' to it

	printf("\n");
	return 0;
}