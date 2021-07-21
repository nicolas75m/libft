#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;

	k = 0;
	while (dst[k] && k < dstsize)
		k++;
	i = k;
	while (src[k - i] && k + 1 < dstsize)
	{
		dst[k] = src[k - i];
		k++;
	}
	if (i < dstsize)
		dst[k] = '\0';
	return (i + ft_strlen(src));
}
