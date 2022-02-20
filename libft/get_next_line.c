/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:08:01 by dha               #+#    #+#             */
/*   Updated: 2022/01/27 16:58:43 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	len;
	char	*str;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i < s1_len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

static int	count_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static char	*split_backup(char	**backup, int fd)
{
	char	*line;
	char	*new_backup;
	int		i;

	if (*backup[fd] == 0)
	{
		free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	i = count_char(backup[fd]);
	line = ft_substr(backup[fd], 0, i + 1);
	if (line == 0)
		return (0);
	new_backup = ft_substr(backup[fd], i + 1, ft_strlen(backup[fd]) - (i + 1));
	if (new_backup == 0)
	{
		free(line);
		return (0);
	}
	free(backup[fd]);
	backup[fd] = new_backup;
	return (line);
}

static int	update_backup(char **backup, int fd, char *buffer)
{
	int	len;

	len = 1;
	while (len != 0 && !ft_strchr(backup[fd], '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(backup[fd]);
			return (0);
		}
		buffer[len] = '\0';
		backup[fd] = gnl_strjoin(backup[fd], buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup[12800];
	char		*buffer;

	if (fd < 0 || fd >= 12800 || BUFFER_SIZE < 1)
		return (0);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	if (backup[fd] == 0)
		return (0);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
	{
		free(backup[fd]);
		return (0);
	}
	if (!update_backup(backup, fd, buffer))
		return (0);
	free(buffer);
	return (split_backup(backup, fd));
}
