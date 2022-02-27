/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:02 by dha               #+#    #+#             */
/*   Updated: 2022/02/27 23:15:57 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

static int	getbit(void)
{
	static int	i = 0;
	static int	recv = 0;

	recv++;
	if (recv > 8)
	{
		i++;
		recv = 1;
	}
	if (g_info.str[i])
		return (g_info.str[i] & (1 << (8 - recv)));
	return (0);
}

static void	send_msg(int sig, siginfo_t *info, void *context)
{
	int	bit;

	bit = getbit();
	if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
	if (sig == SIGUSR1)
	{
		if (!bit)
			kill(g_info.server_pid, SIGUSR1);
		else
			kill(g_info.server_pid, SIGUSR2);
	}
}

static void	check_connect(int sig, siginfo_t *info, void *context)
{
	t_sigact	sigact;
	int			bit;

	ft_putstr_fd("Connect to server(PID: ", 1);
	ft_putnbr_fd(g_info.server_pid, 1);
	ft_putendl_fd(") successfully", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = send_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
	bit = getbit();
	if (!bit)
		kill(g_info.server_pid, SIGUSR1);
	else
		kill(g_info.server_pid, SIGUSR2);
}

void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = check_connect;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_exit("[Error] Wrong parameters(./client [server PID] [msg])");
	g_info.server_pid = ft_atoi(argv[1]);
	if (g_info.server_pid < 100 || g_info.server_pid > 100000)
		error_exit("[Error] Invalid PID");
	g_info.str = (unsigned char *) argv[2];
	show_pid(0);
	init_sigact();
	kill(g_info.server_pid, SIGUSR1);
	while (1)
		pause();
}
