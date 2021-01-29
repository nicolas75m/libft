#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	cs;

	cs = count * size;
	s = malloc(cs);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, cs);
	return (s);
}
