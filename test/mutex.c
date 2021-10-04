#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

pthread_mutex_t lock;

int main()
{
	pthread_t thread[3];

	int tv_time;
	pthread_mutex_init(&lock, NULL);
	printf("%s\n", lock.__opaque);
	printf("%ld",lock.__sig);
	// for (int i = 0; i < 3; i++)
	// {
	// 	pthread_create(&thread[i], NULL, print_log, (void *)&i);
	// 	pthread_detach(thread[i]);
	// }
	// // pthread_create(&thread[1], NULL, print_log, NULL);
	// // pthread_create(&thread[2], NULL, print_log, NULL);
	// // pthread_detach(thread[1]);
	// // pthread_detach(thread[2]);
	// pthread_mutex_destroy(&lock);
	// printf("------Main thread Start-----\n");
	// sleep(6);
	// printf("------Main thread End------\n");
}
