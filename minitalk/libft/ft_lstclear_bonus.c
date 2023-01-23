/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:51:50 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 22:06:05 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == 0)
		return ;
	while ((*lst)->next)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = 0;
}
