#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid = fork();
	if(pid<0)
	{
		printf("perror\n");
	}
	if(pid == 0)
	{
		printf("child created\n");
		printf("pid is %d\n",getpid());
		_exit(0);
	}
	else
	{
		printf("parent\n");
		printf("pid is %d\n",getppid());
		sleep(50);
	}
}
