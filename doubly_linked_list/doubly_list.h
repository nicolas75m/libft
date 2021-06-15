#ifndef DOUBLY_LIST_H
# define DOUBLY_LIST_H

/*
** malloc
** write
*/

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist	*dlist_new(void *content);
void	dlist_add_back(t_dlist **dlist, t_dlist *new);
void	dlist_add_front(t_dlist **dlist, t_dlist *new);
void	dlist_print(t_dlist *dlist);
void	dlist_free(t_dlist *dlist);
void	dlist_remove_start(t_dlist **dlist);
void	dlist_remove_end(t_dlist **dlist);
t_dlist	*dlist_get_end(t_dlist **dlist);

#endif