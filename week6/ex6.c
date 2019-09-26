#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(){
    int status;
    int p[2];
    pipe(p);
    printf("Pipe is created\n");

    // forking processes
    pid_t pid1 = fork();
    //printf("First process is created\n");
    pid_t pid2 = fork();
    //printf("Second process is created\n");


    if (pid1 != 0 && pid2 != 0){
        printf("PARENT PROCESS:\n");
        write(p[1], &pid2, sizeof(pid2));
        printf("Parent writes pid of second process\n");
        printf("Parent waits for state changes in second child\n");
        sleep(1);
        waitpid(pid2, &status, WUNTRACED);
        printf("Parent gets changes in second child\n");
        exit(0);
    }else if (pid1 == 0){
        printf("THE FISRT PROCESS:\n");
        read(p[0], &pid2, sizeof(pid2));
        printf("First process reads data from pipe\n");
        printf("First process sleeps\n");
        sleep(2);
        printf("First process sends signal to the second process\n");
        kill(pid2, SIGSTOP);
        printf("Signal has been sent\n");
    }else if (pid2 == 0){
        printf("THE SECOND PROCESS:\n");
        while (1){
            printf("Second process is alive!\n");
            sleep(1);
        }
    }


}
