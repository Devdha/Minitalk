/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/06/17 13:38:40 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_sigact(void);

static int	handle_char(unsigned char *ch, int *recv)
{
	if (*recv == 8) // when 8 bits received
	{
		if (!(*ch)) // if ch == \0
		{
			write(1, "\n", 1); // output newline
			init_sigact(); // reset signal handler to connect new client
			*ch = 0;
			*recv = 0;
			return (0);
		}
		write(1, ch, 1); // if ch is some character, output the ch.
		*recv = 0;	// reset received bit count to 0
	}
	return (1);
}

static void	recv_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				recv;
	static pid_t			pid;

	(void) context;
	if (!ch && !recv)
		pid = info->si_pid;
	// check sender's pid(sometimes OS control signal, at that time info->si_pid is 0)
	if (pid == info->si_pid || info->si_pid == 0)
	{
		recv++;
		if (sig == SIGUSR1)
			ch &= ~(1 << (8 - recv));
		else if (sig == SIGUSR2)
			ch |= (1 << (8 - recv));
		if (handle_char(&ch, &recv))
			// send signal to notify signal sent by client is confirmed
			kill(pid, SIGUSR1);
		else
			// if all string received, send signal to terminate the client
			kill(pid, SIGUSR2);
	}
	else
		// if pid is not match with current client, terminate process which is sending signal
		kill(info->si_pid, SIGUSR2);
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
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
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
