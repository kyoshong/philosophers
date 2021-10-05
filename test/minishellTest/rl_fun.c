#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int status;
	int return_pid;
	pid_t pid;
	
	return_pid = getpid();
	fork();
	if (return_pid == getpid())
	{
		printf("parent's process\n");
		return_pid = waitpid(-1, &status, WNOHANG);
		printf("parent pid : %d\n", getpid());
		printf("return_pid : %d\n", return_pid);
		printf("status : %d\n", WTERMSIG(status));
	}
	else
	{
		printf("child process\n");
		printf("child pid : %d\n", getpid());
		sleep(3);
		printf("Im a ophant\n");
	}
	exit(1);
}

