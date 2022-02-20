/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:29:00 by dha               #+#    #+#             */
/*   Updated: 2021/12/08 20:27:26 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = '\0';
	return (str);
}
