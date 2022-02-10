/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:39:15 by fkaratay          #+#    #+#             */
/*   Updated: 2022/02/10 14:36:37 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_binary_to_char(int c)
{
	static int	i = 7;
	static int	character = 0;

	character += c << i;
	if (i == 0)
	{
		i = 7;
		write (1, &character, 1);
		character = 0;
	}
	else
		i--;
}

void	signal_handler(int num)
{
	if (num == SIGUSR1)
		get_binary_to_char(1);
	else if (num == SIGUSR2)
		get_binary_to_char(0);
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr("Listening PID Port: ");
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
