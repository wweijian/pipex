/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:50:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/17 09:50:26 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *msg, t_data *data)
{
	perror(msg);
	free_and_exit(data);
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
	while (i < data->cmd_count * 2 - 1)
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
