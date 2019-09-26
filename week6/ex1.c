#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 9

int main(){
  char * some_text = "some text";
  char empty_text[SIZE];
  int p[2];

  if(pipe(p) < 0){
    exit(1);
  }

  write(p[1], some_text, SIZE);
  read(p[0], empty_text, SIZE);
  close(p[1]);
  printf("%s\n", empty_text);
  
  return 0;
}
