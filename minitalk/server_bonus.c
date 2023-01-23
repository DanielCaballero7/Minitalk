/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:52 by dcaballe          #+#    #+#             */
/*   Updated: 2022/11/16 18:02:57 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	recive_str(int sig, siginfo_t *info, void *context)
{
	static char				c;
	static int				i;

	(void)context;
	if (!i)
		i = 1;
	c |= (sig == SIGUSR2);
	if (i++ == 8)
	{
		i = 1;
		if (c == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			ft_putchar_fd(c, 1);
			c = 0;
			kill(info->si_pid, SIGUSR1);
		}
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = recive_str;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
	{
		pause();
		usleep(100);
	}
}
