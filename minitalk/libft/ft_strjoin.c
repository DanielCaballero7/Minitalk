/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:12:06 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 20:12:52 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (s == 0)
		return (0);
	while (*s1 != '\0')
		*s++ = *s1++;
	while (*s2 != '\0')
		*s++ = *s2++;
	*s = '\0';
	return (s + 1 - len);
}
