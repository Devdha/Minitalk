/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:02 by dha               #+#    #+#             */
/*   Updated: 2022/06/17 13:36:37 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info g_info;

static int getbit(void)
{
	static int i = 0;
	static int recv = 0;

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

static void send_msg(int signo)
{
	int bit;

	bit = getbit();
	if (signo == SIGUSR2)
		exit(EXIT_SUCCESS);
	if (signo == SIGUSR1)
	{
		if (!bit)
			kill(g_info.server_pid, SIGUSR1);
		else
			kill(g_info.server_pid, SIGUSR2);
	}
}

static void check_connect(int signo)
{
	int bit;

	(void)signo;
	ft_putstr_fd("Connect to server(PID: ", 1);
	ft_putnbr_fd(g_info.server_pid, 1);
	ft_putendl_fd(") successfully", 1);
	// before: sigaction() -> after: signal()
	if (signal(SIGUSR1, send_msg) == SIG_ERR || signal(SIGUSR2, send_msg) == SIG_ERR)
		error_exit("[Error] Sigaction failed its work.");
	bit = getbit();
	if (!bit)
		kill(g_info.server_pid, SIGUSR1);
	else
		kill(g_info.server_pid, SIGUSR2);
}

void init_sigact(void)
{
	// It doesn't need to use siginfo and context in signal handler,
	// so sigaction() is substituted to signal().
	if (signal(SIGUSR1, check_connect) == SIG_ERR) // when signal() failed, it returns SIG_ERR
		error_exit("[Error] Sigaction failed its work.");
}

int main(int argc, char **argv)
{
	if (argc != 3)
		error_exit("[Error] Wrong parameters(./client [server PID] [msg])");
	g_info.server_pid = ft_atoi(argv[1]);
	if (g_info.server_pid < 100 || g_info.server_pid > 100000)
		error_exit("[Error] Invalid PID");
	g_info.str = (unsigned char *)argv[2];
	show_pid(0);
	init_sigact();
	kill(g_info.server_pid, SIGUSR1);
	while (1)
		pause();
}
