/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:55:41 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:05:35 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		aux_c;
	unsigned char		*aux_str;

	aux_str = (unsigned char *)str;
	aux_c = c;
	while (n--)
	{
		if (*aux_str == aux_c)
			return ((void *)aux_str);
		aux_str++;
	}
	return (0);
}
