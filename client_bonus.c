/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:30:42 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/22 11:35:48 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft/libft.h"
#include <signal.h>

int	g_message_received = 0;

void	print_message(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("\033[0;32mMessage received succesfully!!!\033[0m\n");
		g_message_received = 1;
	}
}

void	ft_process_string(int pid, const char *message)
{
	int	ascii;
	int	bit;
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		ascii = (int)message[i++];
		while (j >= 0)
		{
			bit = (ascii >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(60);
			j--;
		}
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	const char			*message;
	int					i;

	if (argc != 3)
		return (ft_printf("Usage: %s <PID> <String>\n", argv[0]), 0);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, print_message);
	ft_process_string(pid, message);
	i = 8;
	while (i-- > 0)
	{
		kill(pid, SIGUSR2);
		usleep(60);
	}
	while (!g_message_received)
		pause();
	return (0);
}
