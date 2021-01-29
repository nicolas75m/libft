#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
	{
		i++;
	}
	return ((unsigned char)c == s[i] ? ((char*)s + i) : NULL);
}
