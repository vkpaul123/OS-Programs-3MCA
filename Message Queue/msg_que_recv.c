#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct msgBuf
{
	long msgType;
	char mText[MAX];
};

int main()
{
	int msgId;
	int msgFlg=0666;
	int val;
	key_t key=1234;

	struct msgBuf readBuffer;

	msgId = msgget(key, msgFlg);

	if(msgId < 0)
		printf("Error!\n");

	val = msgrcv(msgId, &readBuffer, MAX, 1, 0);

	if(val < 0)
		printf("Error\n");
	else
		printf("%s\n", readBuffer.mText);

	return 0;
}