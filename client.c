/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:42:02 by dha               #+#    #+#             */
/*   Updated: 2022/02/23 19:58:22 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_exit("[Error] Dosen't fit on argument format(./client [server PID] [msg]");
	kill(ft_atoi(argv[1]), SIGUSR1);
	show_pid(0);
}
