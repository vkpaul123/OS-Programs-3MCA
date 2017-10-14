#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *myThread() {
	int i;
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

	printf("Main Thread\n");

	for (i=0; i<10; ++i) {
		printf("Inside Thread %d\n", i);
		sleep(1);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t tid;
	
	pthread_create(&tid, NULL, &myThread, NULL);

	sleep(5);

	pthread_cancel(tid);

	printf("Waiting for the Thread to Close.\n");

	pthread_join(tid, NULL);

	return 0;
}