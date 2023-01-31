/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:44:55 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/01/31 14:57:20 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary(char c, int pid)
{
	int	i;

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

int	main(int ac, char **av)
{
	char	*str;
	int		get_pid;
	int		i;

	if (ac == 3)
	{
		get_pid = ft_atoi(av[1]);
		str = av[2];
		i = 0;
		while (str[i])
		{
			send_binary(str[i], get_pid);
			i++;
		}
	}
	else
		ft_printf("INCORRECT NUMBER OF ARGUMENTS!");
}
