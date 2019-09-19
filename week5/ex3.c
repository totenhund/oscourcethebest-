#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 15

// MUTEX INITIALIZATION
pthread_mutex_t lock;
// MUTEX COND INIT
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

int stack[15];         // Global jar
int top = -1;
int size = 0;

int peek()                  // Return top of the jar
{
  return stack[top];
}

int pop()                   // Delete highest element
{
  int data;
  if(top != -1){
    data = stack[top];
    top--;
    size--;
    return data;
  }else{
    printf("Jar is empty\n");
  }
}

void push(int num)          // Add element at top of jar
{
  if(top != MAXSIZE){
    top++;
    size++;
    stack[top] = num;
  }else{
    printf("Jar is full\n");
  }
}

int produce_cookies()
{
  return rand() % 20 + 1;
}

void *producer(void *vararg)
{
  int cookie = 0;
  pthread_mutex_lock(&lock);
    if(top == 8){
      pthread_cond_wait(&cond1, &lock);
    }else{
      for(int i = top; i < MAXSIZE; i++)
      {
        cookie = produce_cookies();
        printf("Producer: Cookie %d is cooked\n", cookie);
        push(cookie);
        sleep(1);
      }
      pthread_cond_signal(&cond1);
    }
  pthread_mutex_unlock(&lock);
}

void *consumer(void *vararg)
{
  pthread_mutex_lock(&lock);
    if(top == 0){
      pthread_cond_wait(&cond1, &lock);
    }else{
      for(int i = 0; i < 10 && top != 0; i++){
        printf("Consumer: Cookie %d is eaten\n", pop());
        sleep(1);
      }
      pthread_cond_signal(&cond1);
    }
  pthread_mutex_unlock(&lock);
}


int main()
{
  srand(time(0));
  pthread_t id1;
  pthread_t id2;
  pthread_create(&id1, NULL, producer, NULL);
  pthread_create(&id2, NULL, consumer, NULL);
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);


  pthread_mutex_destroy(&lock);

  return 0;
}
