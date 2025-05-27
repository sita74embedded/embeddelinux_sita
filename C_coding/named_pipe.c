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
	char a[100];
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
		printf("named pipe1 child\n");
		printf("Enter the string\n");
		scanf("%s",a);
		fd2=open("fd1",O_WRONLY);
		write(fd2,a,strlen(a)+1);
		}
		close(fd2);
	}
	else
	{
		while(1)
		{
		printf("named pipe1 parent\n");
		fd1=open("fd1",O_RDONLY);
		read(fd1,buf,sizeof(buf));
		printf("%s\n",buf);
		}
		close(fd1);
	}
}	
