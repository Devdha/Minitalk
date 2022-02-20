/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:43:18 by dha               #+#    #+#             */
/*   Updated: 2021/11/29 20:23:39 by dha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && is_set(s1[start], set))
		start++;
	while (end > start && is_set(s1[end], set))
		end--;
	ret = (char *) malloc(sizeof(char) * (end - start) + 2);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}
