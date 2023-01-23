/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:05:01 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:17:49 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	aux_c;
	char	*save;

	aux_c = c;
	save = 0;
	while (*str != '\0')
	{
		if (*str == aux_c)
			save = (char *)str;
		str++;
	}
	if (aux_c == '\0')
		save = (char *)str;
	return (save);
}
