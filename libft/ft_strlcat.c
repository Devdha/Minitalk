/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:52:29 by dha               #+#    #+#             */
/*   Updated: 2021/11/29 18:51:26 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	temp_len;
	size_t	index;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len || dstsize < 1)
		return (src_len + dstsize);
	temp_len = dst_len;
	while (temp_len < dstsize - 1 && src[index] != '\0')
	{
		dst[temp_len] = src[index];
		temp_len++;
		index++;
	}
	dst[temp_len] = '\0';
	return (dst_len + src_len);
}
