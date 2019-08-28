#include <stdio.h>

void print_pyr(int n){
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= (2*n - 1)/2; j++){
      printf(" ");
    }

    for (int j = 1; j <= (2 * i - 1); j++) {
      printf("%c", '*');
    }

    printf("\n");
  }
}


void print_rect(int n){
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < n; j++){
      printf("%c", '*');
    }
    printf("\n");
  }
}


void print_triangle(int n){
  for(int i = 1; i <= n+1; i++){
    for(int j = 1; j <= i; j++){
      printf("%c", '*');
    }
    printf("\n");
  }
}


void print_half_rhombus(int n){

  int len;

  for(int i = 0; i <= n; i++){

    if(i < n/2 + 1){
      len = i;
    }else{
      len = n - i;
    }

    for(int j = 0; j <= len; j++){
      printf("%c", '*');
    }
    printf("\n");
  }
}


int main(int argc, char *argv[]){
  int x;
  sscanf(argv[1], "%d", &x);
  printf("Pyramid:\n\n");
  print_pyr(x);
  printf("\nRectangle:\n\n");
  print_rect(x);
  printf("\nTriangle:\n\n");
  print_triangle(x);
  printf("\nRhombus:\n\n");
  print_half_rhombus(x);
  return 0;
}
