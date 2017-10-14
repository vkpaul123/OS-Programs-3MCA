#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t read_mutex, write_mutex;

void* write() {
	char *ret;
	FILE *f;
	char str[20];

	pthread_mutex_lock(&write_mutex);
	sleep(5);

	pthread_mutex_lock(&read_mutex);

	printf("\nFile Locked. Please Enter the content to be written in the file...\n");
	scanf("%s", str);

	f = fopen("myFile.txt", "w");
	fprintf(f, "%s\n", str);

	fclose(f);

	pthread_mutex_unlock(&read_mutex);
	pthread_mutex_unlock(&write_mutex);
	printf("File Unlocked. File Can be read now.\n");
	
	return ret;
}

void* read() {
	char *ret;
	FILE *f;
	char str[20];

	pthread_mutex_lock(&write_mutex);
	sleep(5);
	pthread_mutex_lock(&read_mutex);

	printf("Opening File.\n");
	f = fopen("myFile.txt", "r");

	fscanf(f, "%s", str);
	printf("File content...\n%s\n", str);
	
	fclose(f);

	pthread_mutex_unlock(&write_mutex);
	pthread_mutex_unlock(&read_mutex);

	return ret;
}

int main()
{
	pthread_t thread_t1, thread_t2;

	int ret;

	ret = pthread_create(&thread_t1, NULL, &write, NULL);
	ret = pthread_create(&thread_t2, NULL, &read, NULL);

	pthread_join(thread_t1, NULL);
	pthread_join(thread_t2, NULL);
	return 0;
}