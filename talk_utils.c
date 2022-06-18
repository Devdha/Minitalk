/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:02 by dha               #+#    #+#             */
/*   Updated: 2022/06/18 15:45:57 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void error_exit(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void show_pid(int is_server)
{
	int pid;

	if (is_server)
		ft_putstr_fd("Server PID: ", 1);
	else
		ft_putstr_fd("Client PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void ft_kill(pid_t pid, int sig)
{
	/* kill()은 아래 케이스에서 실패할 수 있는데,
	1. sig is invalid
	2. pid is invaild
	3. any member of group could not be signaled
	4. given pid is 0 and sending process does not have a process group
	위 케이스 중 최초 연결 후 발생할 수 있는 케이스는 없기 때문에 client 최초 kill만 검증
	*/

	if (kill(pid, sig) == -1)
		error_exit("[Error] Sending signal failed");
}