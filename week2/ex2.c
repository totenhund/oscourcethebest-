#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * get_input(){
  char * word = (char *)malloc(10*sizeof(char));
  printf("Write your word!\n");
  scanf("%s", word);
  return word;
}

void print_reverse(char * word){
  for(int i = strlen(word); i >= 0; i--){
    printf("%c", word[i]);
  }
  printf("\n");
}

int main(){
  print_reverse(get_input());
  return 0;
}
