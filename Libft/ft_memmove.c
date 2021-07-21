#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dst && !src)
		return (0);
	if (dst >= src)
	{
		i = 0;
		dst2 = (unsigned char*)dst;
		src2 = (unsigned char*)src;
		while (len)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
