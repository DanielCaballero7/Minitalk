/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:47:43 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:10:57 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char		aux_c;
	const char	*aux_str;

	aux_str = str;
	aux_c = c;
	while (*aux_str != aux_c && *aux_str)
	{
		aux_str++;
	}
	if (*aux_str == aux_c)
		return ((char *)aux_str);
	return (0);
}
