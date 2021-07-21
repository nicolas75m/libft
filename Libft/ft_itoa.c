#include "libft.h"

int	len(int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int	i;

	i = len(n);
	if (n < 0)
		i++;
	s = malloc(i + 1);
	if (s == NULL)
		return (NULL);
	if (n < 0)
		s[0] = 45;
	s[i] = '\0';
	while (i && s[i - 1] != 45)
	{
		if (n < 0)
			s[i - 1] = -(n % 10) + '0';
		else
			s[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (s);
}
