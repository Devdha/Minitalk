/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/02/28 01:31:14 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	init_sigact(void);

static void	end_recv(pid_t pid)
{
	write(1, "\n", 1);
	kill(pid, SIGUSR2);
	init_sigact();
}

static void	recv_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				recv;
	static pid_t			pid;

	(void) context;
	if (!ch && !recv)
		pid = info->si_pid;
	recv++;
	if (sig == SIGUSR1)
		ch &= ~(1 << (8 - recv));
	else if (sig == SIGUSR2)
		ch |= (1 << (8 - recv));
	if (recv == 8)
	{
		if (!ch)
		{
			end_recv(pid);
			ch = 0;
			recv = 0;
			return ;
		}
		write(1, &ch, 1);
		recv = 0;
	}
	kill(pid, SIGUSR1);
}

static void	connection(int sig, siginfo_t *info, void *context)
{
	int			client_pid;
	t_sigact	sigact;

	(void) sig;
	(void) context;
	client_pid = info->si_pid;
	ft_putstr_fd("Connect to client(PID: ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putendl_fd(") successfully", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = recv_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
	kill(client_pid, SIGUSR1);
}

static void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = connection;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

int	main(void)
{
	show_pid(1);
	init_sigact();
	while (1)
		pause();
}
