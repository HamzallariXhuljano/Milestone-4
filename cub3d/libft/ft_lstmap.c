/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:34 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/24 12:43:12 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// void *ft_f(void *content)
// {
// 	int i;
// 	char *s;
// 	s = strdup(content);
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		s[i] = 97;
// 		i++;
// 	}
// 	s[i] = '\0';
// 	return (s);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*content;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->c);
		newnode = ft_lstnew(content);
		if (newnode == NULL)
		{
			ft_lstclear(&new, del);
			del(content);
		}
		ft_lstadd_back(&new, newnode);
		lst = lst->next;
	}
	return (new);
}

/*int main ()
{
	t_list *nodo;
	//t_list *map;
	
	nodo = ft_lstnew("hello!");
	ft_lstadd_back(&nodo, ft_lstnew("come"));
	ft_lstadd_back(&nodo, ft_lstnew("stai?"));
	
	while (nodo)
	{
		ft_printf("%s\n", (char *)nodo->content);
		nodo = nodo->next;
	}
	map = ft_lstmap(nodo, &ft_f, del); 
	while (map)
	{
		ft_printf("%s\n", (char *)map->content);
		map = map->next;
	}
	//ft_lstclear(&nodo, &del);
	//ft_lstclear(&map, &del);
	return (0); 
}*/
