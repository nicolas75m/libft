#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lnew;

	lnew = (t_list*)malloc(sizeof(t_list));
	if (lnew == NULL)
		return (NULL);
	lnew->content = content;
	lnew->next = NULL;
	return (lnew);
}
