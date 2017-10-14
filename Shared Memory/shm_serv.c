#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
	char c;

	int shmId;
	int shmFlg=IPC_CREAT|0666;
	key_t key=55;
	
	char *shMem, *str;

	shmId = shmget(key, MAX, shmFlg);
	
	if(shmId < 0)
		printf("Error!\n");

	shMem = shmat(shmId, NULL, 0);

	if(shMem == (char*)-1)
		printf("Error!\n");

	str = shMem;

	for(c='A'; c<='Z'; c++)
		*str++ = c;

	*str = NULL;

	while(*shMem != '@')
		sleep(1);

	return 0;
}