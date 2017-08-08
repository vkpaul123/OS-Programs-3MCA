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

double fact(int n) {		//	simple recursive factorial function with less lines of codes and less variables
	if(n == 1)
		return 1;
	else
		return (n * fact(n-1));
} 

int childProcess(int n) {		//get 'n' as parameter
	printf("CHILD PID: %d\n", getpid());

	printf("FACTORIAL of %d is...%lg\n", n, fact(n));	// show factorial of n
}

// MAIN function
int main()
{
	pid_t pid;
	int n;

	printf("Parent PID:\t%d\n", getpid());	// PID of the Parent Process

	//	parent process.	main is the parent process that 
	printf("Enter the value of N to calculate the FACTORIAL...\t");		//	get value of N from parent (main function) to pass it to child
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