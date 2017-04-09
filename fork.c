#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int a = getpid();
	int status;
	printf("%d\n",a);
	pid_t i = fork();
	if(i == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(i == 0)
	{
		printf("This is child process\n");
		pid_t child_pid = getpid();
		printf("%d\n", child_pid);
		sleep(5);
		printf("child is exiting...\n");
	}
	else
	{
		printf("This is parent process\n");
		pid_t parent_pid = getpid();
		printf("%d\n", parent_pid);
		WIFEXITED(&status);
		wait(&status);
		printf("Parent is exiting...\n");
	}
	return 0;
}
