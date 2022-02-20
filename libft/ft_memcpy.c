/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:48:27 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:42:53 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == 0 && src == 0)
		return (0);
	t_src = (unsigned char *) src;
	t_dst = (unsigned char *) dst;
	while (n)
	{
		*t_dst++ = *t_src++;
		n--;
	}
	return (dst);
}
