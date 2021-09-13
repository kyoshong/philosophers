#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

pthread_mutex_t lock;

void *print_log(void *i)
{
	struct timeval tv;
	struct timeval end;

	int j = *(int *)i + 1;
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&lock);
	printf("Start %d thread\n", j);
	printf("End %d thread\n", j);
	pthread_mutex_unlock(&lock);
	gettimeofday(&end, NULL);
	printf("%ld\n", (((end.tv_sec - tv.tv_sec) * 1000) + ((end.tv_usec + tv.tv_usec) / 1000)));
	printf("%d : %ld\n", j,end.tv_sec);
	return NULL;
}

int main()
{
	pthread_t thread[3];

	int tv_time;
	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < 3; i++)
	{
		pthread_create(&thread[i], NULL, print_log, (void *)&i);
		pthread_detach(thread[i]);
	}
	// pthread_create(&thread[1], NULL, print_log, NULL);
	// pthread_create(&thread[2], NULL, print_log, NULL);
	// pthread_detach(thread[1]);
	// pthread_detach(thread[2]);
	pthread_mutex_destroy(&lock);
	printf("------Main thread Start-----\n");
	sleep(6);
	printf("------Main thread End------\n");
}
