/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:43:33 by dha               #+#    #+#             */
/*   Updated: 2022/02/28 00:50:18 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft.h"
# include <signal.h>

typedef struct sigaction	t_sigact;

typedef struct s_info
{
	unsigned char	*str;
	pid_t			server_pid;
}				t_info;

void	show_pid(int is_server);
void	error_exit(const char *str);

#endif