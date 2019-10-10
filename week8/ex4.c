#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int SIZE = 10 * 1024 * 1024; // 10 megabytes
    
    struct rusage rsg;
    for(int i = 0; i < 10; i++){
        int *array = malloc(SIZE);

        memset (array, 0, SIZE);
        getrusage(RUSAGE_SELF, &rsg);
        
        printf("Mem usage: %ld\n", rsg.ru_maxrss);
        sleep (1);
    }
}
