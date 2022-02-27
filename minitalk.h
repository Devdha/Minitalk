/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:43:33 by dha               #+#    #+#             */
/*   Updated: 2022/02/27 16:24:49 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdio.h>

typedef struct sigaction	t_sigact;

typedef struct s_info
{
	unsigned char	*str;
	pid_t			server_pid;
}				t_info;

void	show_pid(int is_server);
void	error_exit(const char *str);

#endif