#include <stdio.h>
#include <sys/types.h>

int main(){

  int n;

  // fork() return 0 if process is child
  if(fork() != 0){
    n = getpid();
    printf("Hello from parent [PID - %d]\n", n);
  }else{
    n = getpid();
    printf("Hello from child [PID - %d]\n", n);
  }

  // Every child process copy the code of parent process and run it
  // pid incremented by one

  return 0;
}
