/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:58:56 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/28 11:34:32 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_array_of_strings(char *string, int num_s, size_t len)
{
	char	**strings;
	size_t	i;
	int		o;

	o = 0;
	i = 0;
	strings = (char **) malloc(sizeof(char *) * (num_s + 1));
	if (strings == 0)
		return (0);
	if (string[i] != '\0')
		strings[o++] = ft_strdup(&string[i]);
	i++;
	while (i < len)
	{
		if (string[i] != '\0' && string[i - 1] == '\0')
			strings[o++] = ft_strdup(&string[i]);
		i++;
	}
	strings[o] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*string;
	size_t	len;
	size_t	i;
	int		num_s;

	if (!s)
		return (0);
	num_s = 0;
	i = 0;
	len = ft_strlen(s);
	string = ft_strdup(s);
	if (string == 0)
		return (0);
	while (i < len)
	{
		if (string[i] == c)
			string[i] = '\0';
		else if (i == 0 || string[i - 1] == '\0')
			num_s++;
		i++;
	}
	strings = ft_array_of_strings(string, num_s, len);
	free(string);
	return (strings);
}
