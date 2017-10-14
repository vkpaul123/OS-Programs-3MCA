#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

struct msgBuf
{
	long msgType;
	char msgText[MAX];
};

int main()
{
	int msgId;
	int msgFlg=IPC_CREAT|0666;
	key_t key=1234;
	
	int val,buffLen;

	struct msgBuf sendBuffer;

	
	msgId = msgget(key, msgFlg);

	if(msgId < 0)
		printf("Error!\n");
	else
		sendBuffer.msgType = 1;

	printf("Enter the Message to be sent to Message Queue...\n");
	scanf("%s", sendBuffer.msgText);

	buffLen = strlen(sendBuffer.msgText) + 1;

	val = msgsnd(msgId, &sendBuffer, buffLen, IPC_NOWAIT);

	if(val < 0)
		printf("Error!\n");
	else
		printf("Message Sent\n");

	return 0;
}