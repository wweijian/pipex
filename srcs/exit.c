/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:50:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 07:57:40 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *prefix, char *suffix)
{
	if (prefix)
		perror(prefix);
	else
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	if (suffix)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(suffix, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	free_and_exit(t_data *data)
{
	(void) data;
	exit(0);
}

void	close_pipe (t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->cmd_count - 1) * 2)
	{
		close(data->pipe[i]);
		i++;
	}
}

void	close_files (t_data *data)
{
	if (data->fd_in >= 0)
		close(data->fd_in);
	if (data->fd_out >= 0)
		close(data->fd_out);
}
