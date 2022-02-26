/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:02 by dha               #+#    #+#             */
/*   Updated: 2022/02/26 21:55:28 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_str;

static int	getbit(void)
{
	static int	i;
	static int	recv;
	
	recv++;
	if (recv > 8)
	{
		i++;
		recv = 1;
	}
	if (g_str[i])
		return (g_str[i] & (1 << (8 - recv)));
	return (0);
}

static void	send_msg(int sig, siginfo_t *info, void *context)
{
	int	bit;

	bit = getbit();
	if (sig == SIGUSR1)
	{
		if (!bit)
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
	}
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

static void	check_connect(int sig, siginfo_t *info, void *context)
{
	t_sigact	sigact;
	int			bit;

	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Connect to server(PID: ", 1);
		ft_putnbr_fd(info->si_pid, 1);
		ft_putendl_fd(") successfully", 1);
		sigact.sa_flags |= SA_SIGINFO;
		sigact.sa_sigaction = send_msg;
		if (sigaction(SIGUSR1, &sigact, NULL) == -1
			|| sigaction(SIGUSR2, &sigact, NULL) == -1)
			error_exit("[Error] Sigaction failed its work.");
		bit = getbit();
		if (!bit)
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
	}
}

void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = check_connect;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error_exit("[Error] Wrong parameters(./client [server PID] [msg])");
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 100000)
		error_exit("[Error] Invalid PID");
	g_str = (unsigned char *) argv[2];
	show_pid(0);
	init_sigact();
	kill(pid, SIGUSR1);
	while (1)
		pause();
}
