#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* func(void* arg)
{
	pthread_detach(pthread_self());
	printf("Inside the thread\n");
	pthread_exit(NULL);
}
void fun()
{
	pthread_t ptid;
	pthread_create(&ptid, NULL, &func, NULL);
	printf("This line is printed before thread terminated\n");
	if(pthread_equal(ptid, pthread_self()))
	{
		printf("threads are equal\n");
	}
	else
	{
		printf("threads are not equal\n");
	}
	pthread_join(ptid,NULL);
	printf("This line is printed after thread ends\n");
	pthread_exit(NULL);
}
int mian()
{
	fun();
	return 0;
}
