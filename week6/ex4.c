#include <stdio.h>
#include <signal.h>


void sig_usr1_handler()
{
    printf(" SIGUSR1\n");
}

void sig_stop_handler()
{
    printf(" SIGSTOP\n");
}

void sig_kill_handler()
{
    printf(" SIGKILL\n");
}

void ctrl_c_handler()
{
    printf(" SIGINT\n");
}

void main()
{
    signal(SIGINT, ctrl_c_handler);
    signal(SIGKILL, sig_kill_handler);
    signal(SIGSTOP, sig_stop_handler);
    signal(SIGUSR1, sig_usr1_handler);
    while(1){}
    // command kill show nothing, thus
    // it means that this is unhandalable
}
