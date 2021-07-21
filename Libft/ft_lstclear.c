#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *begin;
	t_list *ln;

	if (del == NULL || lst == NULL)
		return ;
	begin = *lst;
	while (begin)
	{
		ln = begin->next;
		del(begin->content);
		free(begin);
		begin = ln;
	}
	*lst = NULL;
}
