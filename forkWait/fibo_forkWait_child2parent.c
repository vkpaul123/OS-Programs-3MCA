/*
	UNIX Program to find FIBONACCI of a number given by child process to parent process, using fork() and wait()
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

double fibo(int n) {		//	simple recursive fibobacci function with less lines of codes and less variables
	if(n <= 1)
		return n;
	else
		return (fibo(n-1) + fibo(n-2));
}

//	CHILD PROCESS
int childProcess() {	
	int num;

	printf("PID of Child...\t%d\n", getpid());	//showing PID of child

	printf("Enter the number of fibobacci terms to be shown upto...\n");	//	get number from user
	scanf("%d", &num);

	exit(num);		//	 send "num" as SIGNAL. (We can send only Signals not values from child to parent)
}	


//	MAIN function
int main()
{
	pid_t pid;
	int i, valueFromChild=-1;

	//	forking child process
	pid = fork();

	if(pid < 0) {	//	if child not created
		printf("Error! child not created!");
	}
	else if(pid == 0) {	// if child created, goto "childProcess()" function
		childProcess();
	}

	//	parent process (MAIN is the parent process, as it's forking the child)
	printf("Parent is waiting....\n"); // parent will wait for the child process to complete.

	wait(&valueFromChild);	// waiting for child. Then Storing the SIGNAL from Exit() of ChildProcess, which will be the number that is being passed.

	printf("Child Exited. Parent PID:\t%d\n", getpid());

	int num = valueFromChild / 255; // converting SIGNAL to Integer.

	//fibonacci series
	for(i=0; i<num; i++)
		printf("%lg\n", fibo(i));
	

	printf("\n\n");
	return 0;
}