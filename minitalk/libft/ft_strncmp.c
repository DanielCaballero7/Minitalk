/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:34:27 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:16:06 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*str01;
	const char	*str02;

	str01 = s1;
	str02 = s2;
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*str01 == '\0' && *str02 == '\0')
			return (0);
		if (*str01 != *str02)
		{
			return (*(unsigned char *)str01 - *(unsigned char *)str02);
		}
		str01++;
		str02++;
	}
	return (0);
}
