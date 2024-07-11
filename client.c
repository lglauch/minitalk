/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:11:30 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/20 17:09:28 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "lib/printf/ft_printf.h"
#include <signal.h>

void	send_message(int pid, char *str)
{
	int	i;

	if (!pid || !str)
		return ;
	while (*str)
	{
		i = 7;
		while (i + 1)
		{
			if (*str & (1 << i))
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			i--;
			usleep(250);
		}
		str++;
		usleep(250);
	}
	ft_printf("Message sent\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong parameters\n");
		ft_printf("Usage: ./client [PID] [message]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	send_message(pid, argv[2]);
	return (0);
}
