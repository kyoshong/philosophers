#include <stdio.h>
#include <semaphore.h>

int main()
{
	sem_t *start;

	start = sem_open("/fuck", O_CREAT, 0777, 1);
	while (1)
	{
		/* code */
	}
	
	return 0;
}

