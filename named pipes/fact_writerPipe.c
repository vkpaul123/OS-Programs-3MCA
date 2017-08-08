/*
	UNIX program for named pipes to demonstrate Inter-Process Communication between processes using fifo.
	different reader and writer Processes.

	****STEPS FOR EXECUTION****
	1.	Compile both the programs (Reader and Writer) with a different output file name.
		TERMINAL:		gcc fact_readerPipe.c -o fact_readerPipe
						gcc fact_writerPipe.c -o fact_writerPipe

	2.	Execute the writer process first.
		TERMINAL:		./fact_writerPipe
		(Writer Process will wait for you to open the reader process.)

	3.	Now Open another Terminal Tab or Window. Execute the reader process in the new window.
		TERMINAL:		./fact_readerPipe
		(Reader process will start and wait for the input from the writer process.)

	4.	Go back to the Writer Process Terminal Window/Tab. It will now be waiting for your input for factorial.
		Give the input. This Process will exit as soon as you give the input.

	5.	Go back to the Reader Process Terminal Window/Tab. It will have the output of factorial. Reader will exit after that.

*/ 

// WRITER process

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	int fd;		//	file descriptor for fifo
	char buff[1024];	//	char string for byte-by-byte data transfer

	printf("WRITER:\n");
	mkfifo("myfifo", 0777);		//	making the pipe in read-write-execute mode for all users

	fd = open("myfifo", O_WRONLY);	//	opening pipe in read only mode

	printf("Enter the value of N to find it's Factorial...\t");		//	getting the number into string to write into fifo, byte-by-byte
	scanf("%s", buff);

	write(fd, buff, strlen(buff));	//	writing into fifo byte-by-byte

	printf("'%s' written to pipe.\n", buff);

	close(fd);		//	close file descriptor of fifo
} 
