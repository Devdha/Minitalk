/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:47:03 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:42:54 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *) s;
	while (n)
	{
		if (*tmp_s == (unsigned char) c)
			return ((void *) tmp_s);
		tmp_s++;
		n--;
	}
	return (0);
}
