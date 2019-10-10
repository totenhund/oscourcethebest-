#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main()
{
    int SIZE = 10 * 1024 * 1024; // 10 megabytes	
    for(int i = 0; i < 10; i++){
        int *array = malloc(SIZE);
        memset (array, 0, SIZE);
        sleep (1);
    }
}
