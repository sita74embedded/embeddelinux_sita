#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid=fork();

	if(pid<0)
		printf("perror\n");
	if(pid==0)
	{
		sleep(20);
		printf("child\n pid = %d\n",getpid());
	}
	else
	{
		printf("parent\n pid = %d\n",getppid());
		_exit(0);
	}
}


