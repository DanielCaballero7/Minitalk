/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:00:27 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 22:20:12 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest0;
	const char	*src0;

	if (dest == 0 && src == 0)
		return (0);
	src0 = src;
	dest0 = dest;
	while (n--)
		*dest0++ = *src0++;
	return (dest);
}
