/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:11:33 by lglauch           #+#    #+#             */
/*   Updated: 2024/03/20 16:54:12 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "lib/printf/ft_printf.h"

void	handler(int signal)
{
	static int	count = 0;
	static char	str = 0;

	if (signal == SIGUSR1)
	{
		str = str << 1;
		str = str | 1;
	}
	else
	{
		str = str << 1;
		str = str | 0;
	}
	count++;
	if (count == 8)
	{
		ft_printf("%c", str);
		count = 0;
		str = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
		return (0);
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		usleep(100);
}
