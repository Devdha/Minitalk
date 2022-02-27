/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:01 by dha               #+#    #+#             */
/*   Updated: 2022/02/27 20:48:01 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_sigact(void);

static void	recv_msg(int sig, siginfo_t *info, void *context)
{
	static unsigned char	*ch;
	static int				recv;
	static int				cnt = 1;
	static int				ch_bytes;

	if (!ch)
		ch = malloc(sizeof(char) * 5);
	if (!ch)
		exit(EXIT_FAILURE);
	recv++;
	if (sig == SIGUSR1)
	{
		ch[cnt - 1] &= ~(1 << (8 - recv));
	}
	else if (sig == SIGUSR2)
	{
		if (recv == 1)
			cnt++;
		ch[cnt - 1] |= (1 << (8 - recv));
		if (cnt == 2 && (recv >= 1 && recv <= 4))
			ch_bytes++;
	}
	if (recv == 8)
	{
		if (!ch[cnt - 1])
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
			init_sigact();
			ch = 0;
			recv = 0;
			ch_bytes = 0;
			cnt = 1;
			return ;
		}
		if (!(ch_bytes - cnt + 1))
		{
			write(1, ch, cnt);
			cnt = 1;
			ch_bytes = 0;
			free(ch);
			ch = NULL;
		}
		recv = 0;
	}
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
