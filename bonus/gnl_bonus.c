/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:23:57 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 20:48:25 by wjhoe            ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*output;
	char	*str;

	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	str = NULL;
	str = find_line(fd, str);
	if (!str)
		return (NULL);
	output = make_line(str);
	free(str);
	return (output);
}
