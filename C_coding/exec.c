#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int pid;
	pid=fork();

	if(pid<0)
	{
		printf("error/n");
		exit(1);
	}
	if(pid==0)
	{
		printf("in child\n");
		execl("/bin/ls","ls","-l",NULL);
		perror("exec failed\n");
		exit(1);
	}
	else
	{
		printf("I am in parent\n");
		wait(NULL);
	}
}
