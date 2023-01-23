/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:57:54 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 22:47:23 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		s2 = (char *)malloc(sizeof (char));
		s2[0] = '\0';
		return (s2);
	}
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(sizeof (char) * (len + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, (s + start), len + 1);
	return (s2);
}
