#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int m;
	int ret;

	i = 0;
	m = 1;
	ret = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == 45)
		m = -m;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	ret *= m;
	if (ret < 0 && m == 1)
		return (-1);
	if (ret > 0 && m == -1)
		return (0);
	return (ret);
}
