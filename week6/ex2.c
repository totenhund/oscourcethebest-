#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 9

int main(){
  char * some_text = "some text";
  char empty_text[SIZE];
  int p[2], pid;

  if(pipe(p) < 0){
    printf("Cannot create process\n");
    exit(1);
  }

  // create new process
  pid = fork();

  if(pid > 0){
    close(p[0]);
    write(p[1], some_text, SIZE);
    close(p[1]);
  }else{
    close(p[1]);
    read(p[0], empty_text, SIZE);
    printf("%s\n", empty_text);
    close(p[0]);
  }
  return 0;
}
