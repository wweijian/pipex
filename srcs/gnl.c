/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:23:57 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 13:21:45 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_bonus.h"

static char	*find_line(int fd, char *str)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		str = gnl_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*make_line(char *str)
{
	char		*res;
	size_t		len;
	size_t		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	res = malloc(sizeof(*res) * len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

static char	*remaining_line(char *str)
{
	char	*res;

	if (!str || !str[0])
	{
		free(str);
		return (NULL);
	}
	res = gnl_strdup(gnl_strchr(str, '\n'));
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*str[1024];

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	str[fd] = find_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	output = make_line(str[fd]);
	str[fd] = remaining_line(str[fd]);
	return (output);
}
