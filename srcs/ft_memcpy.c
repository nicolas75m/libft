#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (n)
	{
		*((char*)&dst[i]) = *((char*)&src[i]);
		i++;
		n--;
	}
	return (dst);
}
