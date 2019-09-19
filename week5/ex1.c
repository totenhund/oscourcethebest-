#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10

void *newThread(void *varg){
  printf("Thread is created #%d\n", (int)varg);
  printf("Thread message is printed #%d\n", (int)varg);
  printf("Thread is exit #%d\n", (int)varg);
  return NULL;
}

int main(){
  pthread_t thread_id;
  for(int i = 0; i < NTHREADS; i++){
    pthread_create(&thread_id, NULL, newThread, (void *)i);
    pthread_join(thread_id, NULL); // it fixed everything
                                   // now messages are printed in strict order
                                   // because now other thread would not run
                                   // until the last is not finished    
  }
  pthread_exit(NULL);
  return 0;
}
