/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:34:46 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 17:07:40 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h" 

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst -> next))
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

/*int main()
{
	t_list *nodo;
	t_list *last;
	t_list *niente;
	
	niente = NULL;
	
	nodo = ft_lstnew("ciao");
	//ft_printf("%p\n", nodo); 
	nodo->next = ft_lstnew("come stai");
	nodo->next->next = ft_lstnew("?");
	last = ft_lstlast(nodo);
	ft_printf("%s\n", (char *)nodo->content); 
	return (0);
}*/
