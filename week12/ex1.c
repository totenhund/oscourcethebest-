#include <stdio.h>
#include <stdlib.h>

int main(){

  int rand = open("/dev/random", 'r');
  char rand_data[20];
  if(rand < 0){
    printf("ERROR WITH /dev/random \n");
    exit(0);
  }else{
    size_t rand_data_len = 0;

    while(rand_data_len < sizeof(rand_data)){
      ssize_t result = read(rand, rand_data + rand_data_len, (sizeof(rand_data)) - rand_data_len);
      if(result < 0){
        printf("ERROR WITH READ\n");
        exit(0);
      }
      rand_data_len += result;
    }
    close(rand_data);
  }

  FILE *fp;

  fp = fopen("ex1.txt", "w+");
  fprintf(fp, rand_data);
  close(fp);
}
