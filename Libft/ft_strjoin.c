#include "libft.h"

unsigned long	ft_str_size(char const *s1, char const *s2)
{
	unsigned long	size1;
	unsigned long	size2;

	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;
	return (size1 + size2 + 1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_str_size(s1, s2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		str[i] = s2[k];
		i++;
		k++;
	}
	str[i] = '\0';
	return (str);
}
