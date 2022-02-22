/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:38:28 by dha               #+#    #+#             */
/*   Updated: 2022/02/22 15:51:01 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	unsigned long	tot;
	int				sign;

	sign = 1;
	tot = 0;
	while (is_space(*str))
		str++;
	sign = 1 - (*str == '-' << 1);
	str += (*str == '-' || *str == '+');
	while (*str >= '0' && *str <= '9')
	{
		if (tot > (unsigned long) LONG_MAX / 10 + (sign < 0))
			return ((sign < 0) - 1);
		tot = tot * 10;
		if (tot > (unsigned long) LONG_MAX - (*str - '0') + (sign < 0))
			return ((sign < 0) - 1);
		str++;
	}
	return (tot * sign);
}
