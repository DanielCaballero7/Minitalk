/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:09:01 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:13:22 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (*dst && dstsize)
	{	
		dstsize--;
		len++;
		dst++;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		len++;
		dstsize--;
	}
	if (dstsize)
		*dst = '\0';
	while (*src++)
		len++;
	return (len);
}
