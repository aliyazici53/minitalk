/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:41:30 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/07 13:13:17 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	char_to_binary(int c, int pid)
{
	int	i;
                         //0 1 1 0 0 0 0 1
						 //0 0 0 0 0 0 0 0
	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))   
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc == 3 && *argv[2] != 0)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			char_to_binary(*str, pid);
			str++;
		}
		char_to_binary('\n', pid);
	}
}
