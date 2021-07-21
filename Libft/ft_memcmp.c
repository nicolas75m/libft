#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (n)
	{
		if (*((char*)&s1[i]) != *((char*)&s2[i]))
		{
			if (*((char*)&s1[i]) > *((char*)&s2[i]))
			{
				ret = *((char*)&s1[i]) - *((unsigned char*)&s2[i]);
			}
			else
			{
				ret = -(*((char*)&s2[i]) - *((unsigned char*)&s1[i]));
			}
			break ;
		}
		i++;
		n--;
	}
	return (ret);
}
