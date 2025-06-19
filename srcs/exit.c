/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:50:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 13:41:03 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_exit(t_data *data)
{	
	if (data)
	{
		if(data->cmd)
			free_cmd(data);
		if (data->pid)
			free (data->pid);
		if (data->path_variable)
			free(data->path_variable);
	}
	close_files(data);
	exit(errno);
}

void free_cmd (t_data *data)
{
	int	i;

	i = 0;
	if (data->cmd->command)
		free(data->cmd->command);
	if (data->cmd->options)
	{
		while (data->cmd->options[i])
		{
			free(data->cmd->options[i]);
			i++;
		}
		free(data->cmd->options);
	}
	free(data->cmd);
}

void	close_files (t_data *data)
{
	if (data->fd_in >= 0)
		close(data->fd_in);
	if (data->fd_out >= 0)
		close(data->fd_out);
}

void	error_msg(char *prefix, char *suffix)
{
	if (!suffix)
		perror(prefix);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(suffix, STDERR_FILENO);
	}
}