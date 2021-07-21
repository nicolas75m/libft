#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	lst->next = NULL;
	del(lst->content);
	free(lst);
}
