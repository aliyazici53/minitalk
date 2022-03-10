/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <amzyaziciali1@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:39:15 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/07 13:12:26 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	get_binary_to_char(int c) //for a : 0 1 1 0 0 0 0 1 
								  //for l : 0 1 1 0 1 1 0 0 
								  //for i : 0 1 1 0 1 0 0 1 
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
/*
for a: 2 1 1 2 2 2 2 1 
for l: 2 1 1 2 1 1 2 2
for i: 2 1 1 2 1 2 2 1
*/
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
