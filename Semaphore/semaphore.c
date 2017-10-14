#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 100

pthread_mutex_t myMutex;
pthread_t tIdProducer[MAX], tIDConsumer[MAX];
sem_t empty, full;

int buffer[MAX];
int count=0;

void init() {
	pthread_mutex_init(&myMutex, NULL);

	sem_init(&empty, 1, MAX);
	sem_init(&full, 1, 0);
}

void insertItem(int item) {
	buffer[++count] = item;
}

int removeItem() {
	return buffer[count--];
}

void* producer() {
	int item;
	item = rand() % 100;

	sem_wait(&empty);
	pthread_mutex_lock(&myMutex);

	printf("Produced Item...\t%d\n", item);

	insertItem(item);

	pthread_mutex_unlock(&myMutex);
	sem_post(&full);
}

void* consumer() {
	int item;

	sem_wait(&full);
	pthread_mutex_lock(&myMutex);

	item = removeItem();
	printf("Consumed Item...\t%d\n", item);

	pthread_mutex_unlock(&myMutex);
	sem_post(&empty);
}

int main()
{
	init();

	int n1, n2;

	printf("Enter the Items to be Produced and Consumed...\n");
	scanf("%d %d", &n1, &n2);

	for (int i = 0; i < n1; ++i)
		pthread_create(&tIdProducer[i], NULL, producer, NULL);

	for (int i = 0; i < n2; ++i)
		pthread_create(&tIDConsumer[i], NULL, consumer, NULL);


	for (int i = 0; i < n1; ++i)
		pthread_join(tIdProducer[i], NULL);

	for (int i = 0; i < n2; ++i)
		pthread_join(tIDConsumer[i], NULL);

	sleep(1);

	return 0;
}