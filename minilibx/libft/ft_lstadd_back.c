
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
}
