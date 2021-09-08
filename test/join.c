#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print_log(void *i)
{
	printf("Start %d thread\n", *(int *)i);
	sleep(1);
	printf("End %d thread\n", *(int *)i);
	return NULL;
}

int main()
{
	pthread_t thread[3];
	for (int i = 0; i < 3; i++)
	{
		pthread_create(&thread[i], NULL, print_log, (void *)&i);
		pthread_detach(thread[i]);
	}
	printf("Main thread Start\n");
	sleep(1);
	printf("Main thread End\n");

}
