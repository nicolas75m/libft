#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t k;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (needle[0] == haystack[i])
		{
			k = 0;
			while (haystack[i + k] == needle[k] && needle[k] != '\0' && haystack[i + k] != '\0')
			{
				k++;
				if (i + k > len)
					return (NULL);
			}
			if (k == ft_strlen(needle))
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
