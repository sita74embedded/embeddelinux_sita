#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
int main()
{
	int fd[2];
	int a=pipe(fd);
	char buf[100];
	if(a<0)
	{
		perror("pipe failed");
		return 1;
	}
	printf("%d\n",fd[0]);
	printf("%d\n",fd[1]);

	int c=fork();
	if(c<0)
	{
		perror("fork failed");
		return 1;
	}
	if(c==0)
	{
		printf("i am in child\n");
		read(fd[0],buf,sizeof(buf));
		printf("%s\n",buf);
	}
	else
	{
		printf("i am in parent\n");
		char* message="I am PIPE";
		write(fd[1],message,strlen(message)+1);
	}

}
