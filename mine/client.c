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

int main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3 && av[2] != 0)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		while (*str)
		{
			char_to_binary(*str, pid);
			str++;
		}
		char_to_binary('\n', pid);
	}
}