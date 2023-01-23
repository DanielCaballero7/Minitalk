/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:02:26 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:33 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*aux_s;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	aux_s = ft_strdup(s);
	if (!aux_s)
		return (0);
	while (s[i] != '\0')
	{
		aux_s[i] = f(i, s[i]);
		i++;
	}
	return (aux_s);
}
