/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprincip <sprincip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:34:01 by sprincip          #+#    #+#             */
/*   Updated: 2020/12/27 12:09:46 by sprincip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	string_clear(char *string)
{
	int			i;
	int			size;

	i = 0;
	size = ft_strlen(string);
	while (i < size)
	{
		string[i] = '\0';
		i++;
	}
}

char	*mind_func(char *mind, char **line)
{
	char		*n;

	n = NULL;
	if (mind)
	{
		if ((n = ft_strchr(mind, '\n')))
		{
			*n = '\0';
			n++;
			*line = ft_strdup(mind);
			copy(mind, n);
		}
		else
		{
			*line = ft_strdup(mind);
			string_clear(mind);
		}
	}
	else
		*line = ft_strdup("");
	return (n);
}

int		errors_and_leaks(int i, char **line, char **mind, char *n)
{
	int			k;

	if (i == -1 || *line == NULL)
		return (-1);
	k = ((ft_strlen(*mind) || i || n) ? 1 : 0);
	if (k == 0 && *mind != NULL)
	{
		free(*mind);
		*mind = NULL;
	}
	return (k);
}

int		gnl(int fd, char **line)
{
	static char	*mind;
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*n;
	char		*begin;

	i = 0;
	n = mind_func(mind, line);
	while (!n && (i = read(fd, buf, BUFFER_SIZE)))
	{
		buf[i] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			n++;
			if (mind != NULL)
				free(mind);
			mind = ft_strdup(n);
		}
		begin = *line;
		*line = ft_strjoin(begin, buf);
		free(begin);
	}
	return (errors_and_leaks(i, line, &mind, n));
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		check[0];

	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (read(fd, check, 0) == -1)
		return (-1);
	i = gnl(fd, line);
	return (i);
}
