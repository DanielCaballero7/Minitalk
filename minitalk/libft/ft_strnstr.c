/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:07:27 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:16:37 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len > 0)
	{
		while (*haystack != needle[0] && len > 0 && *haystack != '\0')
		{
			haystack++;
			len--;
		}
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0
			&& ft_strlen(needle) <= len)
			return ((char *)haystack);
		if (len > 0)
			len--;
		if (*haystack != '\0')
			haystack++;
	}
	return (0);
}
