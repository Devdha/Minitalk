/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/02/26 21:52:00 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recv_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				recv;
	
	recv++;
	if (recv > 8)
	{
		if (!ch)
			kill(info->si_pid, SIGUSR2);
		write(1, &ch, 1);
		recv = 1;
	}
	if (sig == SIGUSR1)
		ch &= ~(1 << (8 - recv));
	else if (sig == SIGUSR2)
		ch |= 1 << (8 - recv);
	kill(info->si_pid, SIGUSR1);
}

static void	connection(int sig, siginfo_t *info, void *context)
{
	int			client_pid;
	t_sigact	sigact;

	client_pid = info->si_pid;
	ft_putstr_fd("Connect to client(PID: ", 1);
	ft_putnbr_fd(client_pid, 1);
	ft_putendl_fd(") successfully", 1);
	kill(client_pid, SIGUSR1);
	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = recv_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

static void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = connection;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	printf("%d\n", getpid());
	show_pid(1);
	init_sigact();
	while (1)
		pause();
}
