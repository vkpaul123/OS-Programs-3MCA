#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>

#define MAX 100

int main()
{
	int shmId;
	int shmFlg=0666;
	key_t key=55;

	char *shMem, *str;

	shmId = shmget(key, MAX, shmFlg);

	if(shmId < 0)
		printf("Error!\n");

	shMem = shmat(shmId, NULL, 0);

	if(shMem == (char*)-1)
		printf("Error!\n");

	for(str=shMem; *str!=NULL; str++)
		printf("%c", *str);

	printf("\n");

	*shMem = '@';

	return 0;
}