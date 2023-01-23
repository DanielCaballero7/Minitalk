/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:02:59 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/28 11:20:26 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*first_node;

	if (lst == 0)
		return (0);
	first_node = ft_lstnew(f(lst->content));
	list = first_node;
	if (list == 0)
		return (0);
	while (lst->next)
	{
		list->next = ft_lstnew(f((lst->next)->content));
		if (lst->next == 0)
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		list = list->next;
		lst = lst->next;
	}
	return (first_node);
}
