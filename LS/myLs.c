//	demonstrate LS command from UNIX

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main()
{
	char dirName[30];
	DIR *p;

	struct dirent *d;

	printf("Enter the Directory Name...\t");
	scanf("%s", dirName);

	p = opendir(dirName);

	while(d = readdir(p))
		printf("%s\n", d->d_name);

	return 0;
}