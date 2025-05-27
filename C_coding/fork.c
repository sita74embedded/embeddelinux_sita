#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid=fork();
	printf("*************************\n");
	printf("pid =%d\n",pid);

	if(pid<0)
	{
		printf("*************************\n");
		printf("perror occured\n");
	}
	else if(pid==0)
	{
		printf("*************************\n");
		printf("I am in child\n");
		printf("child created pid is %d\n",getpid());
	}
	else if(pid>0)
	{
		printf("*************************\n");
		printf("I am in parent\n");
		printf("child pid return to the parent %d\n",getpid());
	}
	printf("PARENT PID IS %d\n MY PID is %d\n",getppid(),getpid());
}
