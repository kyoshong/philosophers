#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print_log()
{
	printf("Start thread\n");
	sleep(1);
	printf("End thread\n");
	return NULL;
}

int main()
{
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&thread, &attr, print_log, NULL);
	printf("Main thread Start\n");
	sleep(2);
	printf("Main thread End\n");

}
