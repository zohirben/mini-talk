#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int len = 0;

int ft_atoi(const char *str)
{
    int i;
    int number;
    int sign;

    sign = 1;
    i = 0;
    number = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        number *= 10;
        number += (str[i] - '0');
        i++;
    }
    return (number * sign);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void    send_binary(char c, int pid)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if (c & (1 << i))
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        i--;
        usleep(300);
    }
}

void    handler(int signal)
{
    len+=1;
}

int main(int ac, char **av)
{
    int get_pid;

    if (ac == 3)
    {
        signal(SIGUSR1, handler);
        //dir function kathandli sigusr1 w katdir strlen++
        get_pid = ft_atoi(av[1]);
        char *str = av[2];
        int i = 0;
        while (str[i])
        {
            send_binary(str[i], get_pid);
            i++;
            if (len == ft_strlen(str))
            {
                printf("message is recieved :D\n");
            }
        }
    }
    else
    {
        printf("too few arguments!");
    }
}