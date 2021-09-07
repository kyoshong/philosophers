#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

void *print_log(void *i)
{
	int j = *(int *)i;
	pthread_mutex_lock(&lock);
	printf("Start %d thread\n", j);
	sleep(1);
	printf("End %d thread\n", j);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	pthread_t thread[3];

	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < 3; i++)
	{
		pthread_create(&thread[i], NULL, print_log, (void *)&i);
		pthread_detach(thread[i]);
		sleep(1);
	}
	
	// pthread_create(&thread[1], NULL, print_log, NULL);
	// pthread_create(&thread[2], NULL, print_log, NULL);
	// pthread_detach(thread[1]);
	// pthread_detach(thread[2]);
	pthread_mutex_destroy(&lock);
	printf("------Main thread Start-----\n");
	sleep(1);
	printf("------Main thread End------\n");
}
