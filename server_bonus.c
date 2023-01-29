#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

char signals[8];

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i++] = '\0';
	}
}

int binarytodecimal(char *num)
{
    int i = ft_strlen(num);
    int deci_num = 0;
    int mul = 1;
    while (--i >= 0)
    {
        deci_num = deci_num + (num[i] - 48) * mul;
        mul *= 2;
    }
    ft_bzero(signals, 8);
    return (deci_num);
}

void handler(int sig, siginfo_t *info, void *ucontext)
{
    int siglen;
    static int sender_pid;
    char    c;

    if (sender_pid != info->si_pid)
    {
        ft_bzero(signals, 8);
        sender_pid = info->si_pid;
    }
    siglen = ft_strlen(signals);
    if (sig == SIGUSR1)
    {
        if (siglen != 8)
        {
            signals[siglen] = '0';
        }
    }
    else if (sig == SIGUSR2)
    {
        if (siglen != 8)
        {
            signals[siglen] = '1';
        }
    }
    if (ft_strlen(signals) == 8)
    {      
        c = binarytodecimal(signals);
        write(1, &c, 1);
        kill(sender_pid, SIGUSR1);
    }
}

int main()
{
    struct sigaction action;
    action.sa_sigaction = &handler;
    action.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    printf("%i\n", getpid());
    while(1)
        ;
}