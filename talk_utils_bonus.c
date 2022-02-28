/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:24:02 by dha               #+#    #+#             */
/*   Updated: 2022/02/28 00:49:31 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	error_exit(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	show_pid(int is_server)
{
	int	pid;

	if (is_server)
		ft_putstr_fd("Server PID: ", 1);
	else
		ft_putstr_fd("Client PID: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}
