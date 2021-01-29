#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int	i;

	if (n != -2147483648)
	{
		if (n >= 0)
			i = n;
		else
		{
			i = -n;
			write(fd, "-", 1);
		}
		if (i > 9)
			ft_putnbr_fd(i / 10, fd);
		c = i % 10 + '0';
		write(fd, &c, 1);
	}
	else
		write(fd, "-2147483648", 11);
}
