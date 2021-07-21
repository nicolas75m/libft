#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	if (!src)
		return (0);
	i = 0;
	size = 0;
	if ((int)dstsize < 0)
		return (0);
	while (i < (dstsize - 1) && src[i])
	{
		if ((int)dstsize == 0)
			break ;
		dst[i] = src[i];
		i++;
	}
	if ((int)dstsize != 0)
		dst[i] = '\0';
	while (src[size])
		size++;
	return (size);
}
