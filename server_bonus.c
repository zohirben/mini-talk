/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:44:53 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/01/30 15:19:59 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char signals[8];

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

    (void) ucontext;
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