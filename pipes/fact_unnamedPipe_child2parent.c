/*
	UNIX program to calculate factorial of a number, to demonstrate Inter-Process Communication using Pipes.
	Child will write, Parent will read
 */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

double fact(int n) {
	if(n == 1)
		return 1;
	else
		return (n * fact(n-1));
}

//	CHILD PROCESS
int childProcess(int fd[]) {
	char buff[1024];

	close(fd[0]);	// 	child process closes the input side of the pipe to write
	
	printf("Child:\nEnter the value of N to calculate factorial...\t");	//	get the number in string format. parent process will convert it to integer there.
	scanf("%s", buff);

	write(fd[1], buff, 50);	//	write buffer string (buff) into the pipe

	close(fd[1]);	//	close fd[1] when written.
}

//	PARENT PROCESS
int parentProcess(int fd[]) {
	char buff[1024];

	close(fd[1]);	//	parent process closing the output side of pipe to read.

	read(fd[0], buff, 50);		//	bytes from the pipe read into the buffer string (buff)
	
	int n=atoi(buff);	// converted into integer

	printf("Parent:\nfactorial of %d is...\t%lg\n",n , fact(n));	// show factorial of the collected number
}

//	MAIN
int main() 
{
	int fd[2];	// 2 file decriptors for two sides (output and input)
	int pid; 	// for getting the status of the child to be forked

	pipe(fd);	//	creating a pipe.

	pid = fork();	//	forking a new child process

	if(pid == -1)
		printf("Error in creating Child!\n");
	else if(pid == 0)
		childProcess(fd);
	else
		parentProcess(fd);

	return 0;
}