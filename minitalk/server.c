/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:17 by dcaballe          #+#    #+#             */
/*   Updated: 2022/11/16 18:02:22 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	recive_str(int sig)
{
	static char	c;
	static int	i;

	if (!i)
	{
		i = 1;
		c = 0;
	}
	c |= (sig == SIGUSR2);
	if (i++ == 8)
	{
		ft_putchar_fd(c, 1);
		i = 1;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR1, recive_str);
	signal(SIGUSR2, recive_str);
	while (1)
		pause();
}
