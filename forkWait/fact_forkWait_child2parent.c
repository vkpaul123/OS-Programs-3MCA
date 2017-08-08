/*
	UNIX Program to find FACTORIAL of a number given by child process to parent process, using fork() and wait()
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

//	CHILD PROCESS
int childProcess() {	
	int num;

	printf("PID of Child...\t%d\n", getpid());	//showing PID of child

	printf("Enter the number to calculate FACTORIAL of...\n");	//	get number from user
	scanf("%d", &num);

	exit(num);		//	 send "num" as SIGNAL. (We can send only Signals not values from child to parent)
}	


//	MAIN function
int main()
{
	pid_t pid;
	int valueFromChild=-1;

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

	//factorial
	printf("factorial of %d is...\t%lg",num, fact(num)); // showing factorial by fact() function call
	

	printf("\n\n");
	return 0;
}