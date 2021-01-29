#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	return (str);
}
