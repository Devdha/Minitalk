/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:30:14 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:43:07 by dha              ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	long long		num;
	char			*ret;
	unsigned char	len;
	unsigned char	i;

	len = alen(n);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		ret[i++] = '-';
		len--;
	}
	while (len > 0)
	{
		ret[i++] = (num / pow_ten(len - 1)) + '0';
		num %= pow_ten(len - 1);
		len--;
	}
	ret[i] = '\0';
	return (ret);
}
