#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int global=1;

void* temp_increase(void*arg)
{
	for(int i=1;i<100;i++)
	{
		global=global+1;
	}
	printf("tem increase is %d\n",global);


	pthread_exit(NULL);
}
void* temp_decrease(void*arg)
{
	for(int i=1;i<100;i++)
	{
		global=global-1;
	}

	printf("tem decrease is %d\n",global);
	pthread_exit(NULL);
}

int main()
{
	int*temp=&global;
	pthread_t id1,id2;

	pthread_create(&id1,NULL,temp_increase,NULL);
	pthread_create(&id2,NULL,temp_decrease,NULL);

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
}


