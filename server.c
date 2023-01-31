/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:44:49 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/01/31 15:11:30 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_signals[8];

int	binarytodecimal(char *num)
{
	int	i;
	int	deci_num;
	int	mul;

	i = ft_strlen(num);
	deci_num = 0;
	mul = 1;
	while (--i >= 0)
	{
		deci_num = deci_num + (num[i] - 48) * mul;
		mul *= 2;
	}
	ft_bzero(g_signals, 8);
	return (deci_num);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	int			siglen;
	static int	sender_pid;
	char		c;

	(void)ucontext;
	if (sender_pid != info->si_pid)
	{
		ft_bzero(g_signals, 8);
		sender_pid = info->si_pid;
	}
	siglen = ft_strlen(g_signals);
	if (siglen != 8)
	{
		if (sig == SIGUSR1)
			g_signals[siglen] = '0';
		else if (sig == SIGUSR2)
			g_signals[siglen] = '1';
	}
	if (ft_strlen(g_signals) == 8)
	{
		c = binarytodecimal(g_signals);
		write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("%i\n", getpid());
	while (1)
		;
}
