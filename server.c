/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/02/23 20:03:15 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recv_msg(int sig, siginfo_t *info, void *context)
{
	
}

void	connection(int sig, siginfo_t *info, void *context)
{
	int			client_pid;
	t_sigact	sigact;

	client_pid = info->si_pid;
	kill(SIGUSR1, client_pid);
	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = recv_msg;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

void	init_sigact(void)
{
	t_sigact	sigact;

	sigact.sa_flags |= SA_SIGINFO;
	sigact.sa_sigaction = connection;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed its work.");
}

int	main(int argc, char **argv)
{
	show_pid(1);
	init_sigact();
	while (1)
		pause();
}
