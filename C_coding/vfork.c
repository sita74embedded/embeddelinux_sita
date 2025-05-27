#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid=vfork();

	if(pid<0)
	{
		printf("perror\n");
	}
	else if(pid==0)
	{
		printf("child created\n child pid=%d\n",getpid());
		_exit(0);
	}
	else if(pid>1)
	{
		printf("parent created\n");
	}
	printf("parent pid is %d \n my pid is %d\n",getppid(),getpid());
}		




