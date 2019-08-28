#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(){

  int int_var = INT_MAX;
  float float_var = FLT_MAX;
  double double_var = DBL_MAX;

  printf("Int value:%d, Size:%ld\n", int_var, sizeof(int_var));
  printf("Float value:%f, Size:%ld\n", float_var, sizeof(float_var));
  printf("Double value:%f, Size:%ld\n", double_var, sizeof(double_var));

  return 0;
}
