/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:42:55 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:08:15 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*aux_dst;
	const char	*aux_src;
	size_t		aux_len;

	aux_dst = dst;
	aux_src = src;
	aux_len = len;
	if (dst == src || !len)
		return (dst);
	if (aux_dst < aux_src)
	{
		while (aux_len--)
			*aux_dst++ = *aux_src++;
	}
	else
	{
		aux_dst = dst + len - 1;
		aux_src = src + len - 1;
		while (aux_len--)
		*aux_dst-- = *aux_src--;
	}
	return (dst);
}
