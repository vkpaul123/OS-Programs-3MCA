//	UNIX program to demonstrate fork system call

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h> 

int childProcess() {
	int i;
	for(i=0; i<10; i++)		//	simple for loop to show childProcess activity
		printf("\nLine %d from CHILD Process: %d\n", i, getpid());
}

int parentProcess() {
	int i;
	for(i=0; i<10; i++)		//	simple for loop	to show parentProcess activity
		printf("\nLine %d from PARENT Process: %d\n", i, getpid());
}

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = fork();	//	forking the child

	if(pid == -1)	//	child not created
		printf("\nError! Child Not created!\n");
	else if(pid == 0)	//	childProcess
		childProcess();
	else	//	parentProcess
		parentProcess();

	return 0;
}