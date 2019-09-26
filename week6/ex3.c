#include <stdio.h>
#include <signal.h>


void ctl_C_Handler(int sig_num){
    printf("\n Why you pressed Ctrl+C, do not close me please\n");
}

int main (){

    signal(SIGINT, ctl_C_Handler);
    while(1){}
    return 0;
}
