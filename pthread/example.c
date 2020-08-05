#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_sleep(void *ptr){
  printf("Starting th %lx\n", pthread_self());
  sleep(1);
  printf("Done th %lx\n", pthread_self());
}

int main()
{
  printf("Main thread that will run benchmark\n");

  pthread_t tid;

  void *vp = NULL;
  pthread_create(&tid, NULL, thread_sleep, vp);
  pthread_join(tid, NULL);

  printf("All done\n");
}
