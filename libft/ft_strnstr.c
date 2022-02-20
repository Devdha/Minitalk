/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:04:07 by dha               #+#    #+#             */
/*   Updated: 2021/11/29 19:47:12 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (haystack[i] && needle[i] && haystack[i] == needle[i] && i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (0);
}
