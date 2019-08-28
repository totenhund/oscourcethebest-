#include <stdio.h>
#define put(expr) printf(#expr " = %d\n", expr)

void swap(int * a, int * b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int x;
  int y;
  printf("Write the value of x\n");
  scanf("%d", &x);
  printf("Write the value of y\n");
  scanf("%d", &y);
  printf("Before swaping:\n");
  put(x);
  put(y);
  printf("After swaping:\n");
  swap(&x, &y);
  put(x);
  put(y);
  return 0;
}
