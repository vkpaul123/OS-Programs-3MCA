//	demonstrate copy program in UNIX

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int srcFD, destFD, nbread;
	char buff[1024];

	if(argc != 3)
		printf("Invalid Number of argumets!\nUSAGE:\t copy <source_file> <destination_file>\n");

	srcFD = open(argv[1], O_RDONLY);

	destFD = open(argv[2], O_WRONLY | O_CREAT);

	while((nbread = read(srcFD, buff, 1024)) > 0)
		write(destFD, buff, nbread);

	close(srcFD);
	close(destFD);

	return 0;
}