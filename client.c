/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:41:30 by fkaratay          #+#    #+#             */
/*   Updated: 2022/02/10 14:37:02 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(int c, int pid)
{
	int	i;

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

	if (argc == 3)
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
