#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			k = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char*)s + i);
	return ((unsigned char)c == s[k] ? ((char*)s + k) : NULL);
}
