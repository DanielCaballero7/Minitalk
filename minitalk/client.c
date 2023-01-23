/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:01 by dcaballe          #+#    #+#             */
/*   Updated: 2022/11/16 18:02:09 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sendbits(int pid, char *s)
{
	int		bit;
	char	c;

	bit = 7;
	while (*s)
	{
		c = *s++;
		while (bit >= 0)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit--;
			usleep(200);
		}
		bit = 7;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	sendbits(ft_atoi(argv[1]), argv[2]);
	return (0);
}
