/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:56 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:42:44 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	alen(int n)
{
	long long		num;
	unsigned char	len;

	if (n == 0)
		return (1);
	len = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static unsigned int	pow_ten(unsigned char exp)
{
	unsigned int	ret;

	ret = 1;
	while (exp--)
		ret *= 10;
	return (ret);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long		num;
	unsigned char	len;
	unsigned char	c;

	len = alen(n);
	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
		len--;
	}
	while (len > 0)
	{
		c = (num / pow_ten(len - 1)) + '0';
		num %= pow_ten(len - 1);
		write(fd, &c, 1);
		len--;
	}
}
