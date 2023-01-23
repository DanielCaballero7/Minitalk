/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:40 by dcaballe          #+#    #+#             */
/*   Updated: 2022/11/16 18:02:45 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include <stdlib.h>

void	recive_signals(int sig)
{
	static int	i;

	if (!i)
		i = 0;
	if (sig == SIGUSR1)
		i++;
	else
	{
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	sendbits(int pid, char *s)
{
	int		bit;
	char	c;

	bit = 7;
	while (*s != '\0')
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
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	signal(SIGUSR1, recive_signals);
	signal(SIGUSR2, recive_signals);
	ft_putstr_fd("Sent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Recived: ", 1);
	sendbits(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
