/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:44:47 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/01/30 15:23:05 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int len = 0;

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
    (void) signal;
    len+=1;
}

int main(int ac, char **av)
{
    int get_pid;

    if (ac == 3)
    {
        signal(SIGUSR1, handler);
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