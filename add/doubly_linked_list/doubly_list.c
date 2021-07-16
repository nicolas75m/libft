/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprincip <sprincip@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:20:56 by sprincip          #+#    #+#             */
/*   Updated: 2021/06/14 18:46:31 by sprincip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_list.h"

t_dlist	*dlist_new(void *content)
{
	t_dlist	*new;

	if (content == NULL)
		return (NULL);
	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	dlist_add_back(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*begin;

	if (dlist == NULL || new == NULL)
		return ;
	if (*dlist == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*dlist = new;
		return ;
	}
	begin = *dlist;
	while (begin->next)
		begin = begin->next;
	begin->next = new;
	new->next = NULL;
	new->prev = begin;
}

void	dlist_add_front(t_dlist **dlist, t_dlist *new)
{
	if (dlist == NULL || new == NULL)
		return ;
	if (*dlist == NULL)
	{
		*dlist = new;
		return ;
	}
	new->next = *dlist;
	(*dlist)->prev = new;
	*dlist = new;
}

void	str_print(char *str)
{
	int		i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	dlist_print(t_dlist *dlist)
{
	t_dlist	*copy;

	copy = dlist;
	while (copy)
	{
		str_print(copy->content);
		write(1, "\n", 1);
		copy = copy->next;
	}
}

void	dlist_free(t_dlist *dlist)
{
	t_dlist	*mind;

	while (dlist)
	{
		mind = dlist->next;
		free(dlist->content);
		free(dlist);
		dlist = mind;
	}
}

void	dlist_remove_start(t_dlist **dlist)
{
	t_dlist	*mind;

	if (dlist == NULL)
		return ;
	mind = *dlist;
	*dlist = (*dlist)->next;
	free(mind->content);
	free(mind);
}

t_dlist	*dlist_get_end(t_dlist **dlist)
{
	t_dlist	*begin;

	if (dlist == NULL)
		return (NULL);
	begin = *dlist;
	while (begin->next)
		begin = begin->next;
	return (begin);
}

void	dlist_remove_end(t_dlist **dlist)
{
	t_dlist	*begin;
	t_dlist	*mind;

	if (dlist == NULL)
		return ;
	begin = *dlist;
	while (begin->next)
		begin = begin->next;
	mind = begin;
	begin->prev->next = NULL;
	free(mind->content);
	free(mind);
}