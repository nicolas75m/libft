#include "libft.h"

int	words_count(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			k++;
			while (s[i] && s[i] != c)
			{
				i++;
				k++;
			}
		}
	}
	return (k);
}

char	*ft_word(char const *s, char c)
{
	char	*word;
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char*)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free(char **words, int count)
{
	while (count >= 0)
	{
		free(words[count]);
		count--;
	}
	free(words);
}

char	**ft_words(char const *s, char c)
{
	char	**words;
	int	count;
	int	i;

	count = 0;
	i = 0;
	if ((words = (char**)malloc(sizeof(char*) * (words_count(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if ((words[count] = ft_word(&s[i], c)) == NULL)
			{
				ft_free(words, count);
				return (NULL);
			}
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	words[count] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = ft_words(s, c);
	return (str);
}
