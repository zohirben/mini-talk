#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void print0(int sig)
{
    write(1, "0", 1);
}

void print1(int sig)
{
    write(1, "1", 1);
}

int main()
{
    signal(SIGUSR1, print0);
    signal(SIGUSR2, print1);
    printf("%i\n", getpid());
    while(1)
        ;
}