#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i = (lo - 1);

    for (int j = lo; j <= hi - 1; j++){

        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[hi]);
    return (i + 1);
}


void quick_sort(int arr[], int lo, int hi){
    if (lo < hi){

        int p = partition(arr, lo, hi);

        quick_sort(arr, lo, p - 1);
        quick_sort(arr, p + 1, hi);
    }
}


void print_array(int arr[], int size){
    int i;
    for (i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
}


int main(){
    int arr[] = {0, 21321, 421, 12, 23213, 2, 32, 41, 4343};
    int len = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, len-1);
    print_array(arr, len);
    return 0;
}
