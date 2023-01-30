/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:13:17 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/01/30 15:08:23 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK
# define MINITALK

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int ft_atoi(const char *str);
int ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);

#endif