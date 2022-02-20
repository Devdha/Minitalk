/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:49:17 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:42:51 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == 0 && src == 0)
		return (0);
	t_src = (unsigned char *) src;
	t_dst = (unsigned char *) dst;
	if (t_dst <= t_src)
	{
		while (len)
		{
			*t_dst++ = *t_src++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			len--;
			t_dst[len] = t_src[len];
		}
	}
	return (dst);
}
