#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    pid_t pid = fork();

    if (pid == 0){
        while (1){
            printf("I am alive\n"); // print every second I am alive
            sleep(1);
        }
    }else{
        sleep(10);
        kill(pid, SIGTERM); // killing process
    }
}
