#include "minitalk.h"

void	put_binary_to_char(int n) 
{
	static int	i = 7;
	static int	chr = 0;

	chr += n << i;
	if (i == 0)
	{
		write(1, &chr, 1);
		i = 7;
		chr = 0;
	}
	else
		i--;
}

void	sig_handler(int num)
{
	if (num == SIGUSR1)
		put_binary_to_char(1);
	else if (num == SIGUSR2)
		put_binary_to_char(0);
}

int main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler); 
	ft_putstr("PID:\t");
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}