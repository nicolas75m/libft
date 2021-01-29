#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*newstr;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	newstr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
