/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:10:35 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:43:14 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	tot;
	int	sign;

	sign = 1;
	tot = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			break ;
		tot = tot * 10 + (*str - '0');
		str++;
	}
	return (tot * sign);
}
