//	UNIX program to simulate grep command.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	FILE *fp=fopen(argv[1], "r");
	int countLines=0, countOccur=0;
	char buff[1024], *newline;

	if(argc != 3) {
		printf("Invalid Arguments!\nUSAGE:\t ./a.out <fileName> <Word>\n");
		exit(0);
	}

	while(fgets(buff, 1024, fp) != NULL) {
		countLines++;

		if(newline = strchr(buff, '\n'))
			*newline = '\0';

		if(strstr(buff, argv[2]) != NULL) {
			printf("\nFile Name: %s\nLine No.: %d\nWord: %s", argv[1], countLines, buff);
			countOccur++;
		}
	}

	printf("\n\nOccurances: %d", countOccur);

	printf("\n");
	return 0;
}
