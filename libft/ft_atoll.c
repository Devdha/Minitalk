/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:38:28 by dha               #+#    #+#             */
/*   Updated: 2022/02/11 16:21:28 by dha              ###   ########seoul.kr  */
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

long long	ft_atoll(const char *str)
{
	long long	tot;
	int			sign;

	sign = 1;
	tot = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	str += (*str == '-' || *str == '+');
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			break ;
		if (tot > 922337203685477581 || tot < -922337203685477581)
			return (-1);
		tot = tot * 10 + (*str - '0') * sign;
		if ((sign > 0 && tot < 0) || (sign < 0 && tot > 0))
			return (-1);
		str++;
	}
	return (tot);
}
