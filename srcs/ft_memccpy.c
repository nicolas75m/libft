#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	unsigned char	c2;

	i = 0;
	c2 = c;
	while (i < n && *((unsigned char*)&src[i]) != c2)
	{
		*((unsigned char*)&dst[i]) = *((unsigned char*)&src[i]);
		i++;
	}
	if (*((unsigned char*)&src[i]) == c2)
	{
		*((unsigned char*)&dst[i]) = c2;
		return (dst + i + 1);
	}
	return (NULL);
}
