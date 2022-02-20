/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:04:30 by dha               #+#    #+#             */
/*   Updated: 2021/11/28 19:42:29 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	s_len = ft_strlen(s);
	if (s_len <= start || len == 0 || s_len == 0)
		return ((char *) ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
