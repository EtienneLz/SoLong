#include "../includes/solong.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void            my_mlx_pixel_put(t_struct *stru, int x, int y, int color)
{
    char    *dst;
    dst = stru->data.addr + (y * stru->data.line_length + x * (stru->data.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

unsigned int	mlx_get_pixel(t_struct *stru, int x, int y, int w_img)
{
	return (*(unsigned int *)(stru->texture[w_img].addr + (x * stru->texture[w_img].bits_per_pixel / 8 + y * stru->texture[w_img].line_length)));
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
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