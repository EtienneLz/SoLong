#include "../includes/solong.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		write(fd, "147483648", 9);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-', fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar(n % 10 + '0', fd);
		}
		else
		{
			ft_putchar(n + '0', fd);
		}
	}
}