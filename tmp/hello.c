#include <stdio.h>
#include <pthread.h>

int main(){

	pthread_t newThrd;
	int er = pthread_create (&newThrd, NULL, NULL, NULL);

	printf("hello\n");
return 0;
}

