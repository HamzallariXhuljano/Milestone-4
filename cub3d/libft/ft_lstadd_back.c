/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:05:40 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 19:14:54 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

/*t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst -> next))
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = (t_list *)malloc (sizeof(*nodo));
	if (nodo == NULL)
		return (NULL);
	nodo -> content = content;
	nodo -> next = NULL;
	return (nodo);
}

int main()
{
	t_list *lst;
	t_list *new;

	lst = ft_lstnew("Ciao");
	new = ft_lstnew("come stai");	
	ft_lstadd_back(&lst, new);
	ft_printf("%s", (char *)lst->next->content);
	return (0);
}*/
