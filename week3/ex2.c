#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int array[], int len){
  for(int i = 0; i < len; i++){
    for(int j = 0; j < len; j++){
      if(array[i] < array[j]){
        swap(&array[i], &array[j]);
      }
    }
  }
}

void print_array(int array[], int len){
  for(int i = 0; i < len; i++){
    printf("array[%d] = %d\n", i, array[i]);
  }
}


int main(){
  int array[] = {4, 32, 1, 23, 4, 54, 657, 21};
  int len = sizeof(array)/sizeof(int);
  bubble_sort(array, len);
  print_array(array, len);
  return 0;
}
