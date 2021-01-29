#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			ret = 0;
		else
		{
			ret = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	if (n > i && s1[i] && !s2[i])
		ret = (unsigned char)s1[i];
	if (n > i && s2[i] && !s1[i])
		ret = -(unsigned char)s2[i];
	return (ret);
}
