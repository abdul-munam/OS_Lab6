#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Process Thread is being created \n");
	return NULL;
}

int main()
{
	pthread_t thread_id;
	printf("Before Creation of Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Creation of Thread\n");
	exit(0);
}	
