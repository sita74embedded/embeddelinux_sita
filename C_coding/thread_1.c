#include<stdio.h>
#include<pthread.h>
void* my_thread(void* arg)
{
	printf("%s\n",(char*)arg);
}
int main()
{
	pthread_t thread_id;
	char* message="my_thread";
	pthread_create(&thread_id, NULL, my_thread, (void*)message);

	pthread_join(thread_id,NULL);
}
