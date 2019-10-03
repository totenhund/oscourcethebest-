#include <stdio.h>
#include <stdlib.h>

int main() {


    int n;
    printf("Enter N:");
    scanf("%d", &n);

    int * array = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        array[i] = i;
        printf("%d\n", array[i]);
    }

    free(array);
    array = NULL;

    return 0;
}
