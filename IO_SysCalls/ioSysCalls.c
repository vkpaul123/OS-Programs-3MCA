//	IO System Calls. open() close() read() write() lseek()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int ch, fd;
	char buff[1024];
	char file[15] = "myFile.txt";

	while(1) {
		printf("\n\n\n***MENU***");
		printf("\n1) Create File\t write()");		//	open()	->	write()	->	close()
		printf("\n2) Read from File\t read()");		//	open()	->	read() 	->	close()
		printf("\n3) Move Pointer\t seek()");		//	open()	->	lseek()	->	close()
		printf("\n0) Exit");
		printf("\nEnter Your Choice...\t");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
			//	CREATE FILE
				fd = open(file, O_WRONLY | O_CREAT);	//	file created
				printf("Enter the content to be written in the file...\n");		//	get content
				scanf("%s", buff);

				write(fd, buff, strlen(buff));		//	write into file byte-by-byte
				close(fd);		//	close file

				break;
			
			case 2:
			//	READ FROM FILE
				fd = open(file, O_RDONLY);	//	open file

				printf("\nContent read from the File...\n");	//	showing file content
				while(read(fd, buff, 50) > 0)
					write(1, buff, 5);	//	write 5 bytes at a time

				close(fd);	//	close file

				break;
			
			case 3:
			//	MOVE POINTER
				fd = open(file, O_RDONLY);	//	open file

				lseek(fd, 5, SEEK_SET);	//	offset set to 5

				printf("\nContent read from the File...\n");	//	showing file content
				while(read(fd, buff, 50) > 0)
					write(1, buff, 5);	//	write 5 bytes at a time

				close(fd);	//	close file

				break;


			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!");
		}
	}

	printf("\n");
	return 0;
}