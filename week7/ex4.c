#include <stdio.h>
#include <stdlib.h>

void * my_realloc(void * ptr, int size){

    void * new_ptr;

    if(ptr == NULL){
        ptr = malloc(size);
        return ptr;
    } else if(size == 0){
        free(ptr);
        ptr = NULL;                 // avoiding dangle pointers
        return ptr;
    }else{
        new_ptr = malloc(size);
        new_ptr = ptr;
        free(ptr);                  // free old pointer
        ptr = NULL;                 // avoiding dangle pointers
        return new_ptr;
    }

}

int main() {

    int * arr = malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++){
        arr[i] = i;
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    // example to check if it works
    printf("\n");
    arr = my_realloc(arr, sizeof(6 * sizeof(int)));
    arr[5] = 9;
    arr[6] = 12;
    for (int j = 0; j < 7; ++j) {
        printf("%d ",arr[j]);
    }

}
