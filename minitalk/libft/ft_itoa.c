/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:32:24 by dcaballe          #+#    #+#             */
/*   Updated: 2022/06/24 22:30:43 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itoa(int n)
{
	char	str[13];
	int		len;
	int		sign;
	long	num;

	num = (long) n;
	sign = 0;
	len = 12;
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		sign = 1;
		num = num * -1;
	}
	while (num > 0)
	{
		str[len--] = (char)(num % 10 + '0');
		num /= 10;
	}
	if (sign == 1)
		str[len--] = '-';
	if (n == 0)
		str[len--] = '0';
	return (ft_strdup(&str[len + 1]));
}
