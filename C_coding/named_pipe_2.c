#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd1,fd2;
	char buf[100];
	char *a;
	
	mkfifo("fd1",0666);
	
	int c=fork();

	if(c<0)
	{
		perror("fork failed");
		return 1;
	}
	if(c==0)
	{
		
		while(1)
		{
		printf("named pipe2 child\n");
		printf("Enter the string\n");
		scanf("%s",a);
		write(fd2,a,strlen(a+1));
		}
	}
	else
	{

		while(1)
		{
		printf("named pipe2 parent\n");
		read(fd1,buf,sizeof(buf));
		}
	}
}	
