/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:10:54 by temil-da          #+#    #+#             */
/*   Updated: 2024/05/24 15:38:02 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft/libft.h"
#include <signal.h>

void	ft_put_logo(void)
{
	ft_printf("\n _   .-')                 .-') _         .-') _      ('-.  ");
	ft_printf("            .-. .-')   \n( '.( OO )_              ( OO ) )    ");
	ft_printf("   (  OO) )    ( OO ).-.          \\  ( OO )  \n\033[31m ,--. ");
	ft_printf("  ,--.\033[37m)\033[33m ,-.\033[37m-') \033[32m,--.\033[37m/");
	ft_printf("\033[32m ,--,' \033[36m,-.\033[37m-') /     '._   / . --. /");
	ft_printf("\033[38;5;208m ,--.     \033[38;5;165m,--. ,--.  \n\033[31m | ");
	ft_printf("  `.'   | \033[33m |  |\033[37mOO)\033[32m|   \\ |  |\033[37m");
	ft_printf("\\ \033[36m|  |\033[37mOO)\033[34m|'--\033[37m...__)\033[35m  ");
	ft_printf("| \033[37m\\\033[35m-.  \\ \033[38;5;208m |  |\033[37m.-') ");
	ft_printf("\033[38;5;165m|  .'   /  \n\033[31m |         | \033[33m |  |");
	ft_printf("\033[37m  \\\033[32m|    \\|  |\033[37m )\033[36m|  |\033[37m");
	ft_printf("  \\\033[34m'--.  .--'\033[35m\033[37m.-\033[35m'-'  |  |");
	ft_printf("\033[38;5;208m |  |\033[37m OO )\033[38;5;165m");
}

void	ft_put_logo_2(void)
{
	ft_printf("|      /\033[37m,  \n\033[31m |  |'.'|  | \033[33m ");
	ft_printf("|  |\033[37m(_/\033[32m|  .     |\033[37m/ \033[36m|  |");
	ft_printf("\033[37m(_/\033[34m   |  |   \033[37m \\\033[35m| |_.'  |");
	ft_printf("\033[38;5;208m |  |\033[37m`-' |\033[38;5;165m|     ' ");
	ft_printf("\033[37m_) \n\033[31m |  |   |  |\033[37m ,\033[33m|  |");
	ft_printf("\033[37m_.'\033[32m|  |\\    |\033[37m ,\033[36m|  |\033[37m_.");
	ft_printf("'\033[34m   |  |   \033[35m  |  .-.  |\033[37m(\033[38;5;208m|");
	ft_printf("  '---.'\033[38;5;165m|  .   \\   \n\033[31m |  |   |  |");
	ft_printf("\033[37m(_\033[33m|  |   \033[32m|  |  |  |\033[34m  |  |   ");
	ft_printf("\033[34m   |  |  \033[35m   |  | |  |\033[38;5;208m |      | ");
	ft_printf("\033[38;5;165m|  |\\   \\  \n\033[31m `--'   `--'  \033[33m`--");
	ft_printf("'   \033[32m`--'  `--'  \033[36m`--'   \033[34m   `--'   ");
	ft_printf("\033[35m  `--' `--'\033[38;5;208m `------' \033[38;5;165m`");
	ft_printf("--' '--'  \033[37m\n");
}

void	print_character(char *output, int *i)
{
	if (*output != '\0')
		write(1, output, 1);
	else
		write(1, "\n", 1);
	*output = 0;
	*i = 0;
}

void	handle_signals_mini(int signal, siginfo_t *siginfo, void *context)
{
	static char		output = 0;
	static int		i = 0;
	static int		temp_pid = 0;

	(void)context;
	if (siginfo)
	{
		if (temp_pid != siginfo->si_pid)
		{
			temp_pid = siginfo->si_pid;
			output = 0;
			i = 0;
		}
	}
	if (i != 8)
	{
		if (signal == SIGUSR1)
			output = output | (1 << (7 - i));
		i++;
	}
	if (i == 8)
		print_character(&output, &i);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handle_signals_mini;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_put_logo();
	ft_put_logo_2();
	pid = getpid();
	ft_printf("\nPID : %d\n\n", pid);
	while (1)
		pause();
	return (0);
}
