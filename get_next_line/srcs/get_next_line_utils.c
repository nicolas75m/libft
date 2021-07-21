/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprincip <sprincip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:34:12 by sprincip          #+#    #+#             */
/*   Updated: 2020/12/23 19:54:18 by sprincip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return ((s[i] == c) ? ((char*)s + i) : NULL);
}

void	copy(char *to, const char *from)
{
	int		i;

	i = 0;
	while (from[i])
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	copy(str, s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
