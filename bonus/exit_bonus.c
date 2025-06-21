/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:50:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 19:43:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_and_exit(t_data *data)
{
	close_files(data);
	if (data)
	{
		if (data->heredoc == 1)
			unlink(".heredoc");
		if (data->cmd)
			free_cmd(data);
		if (data->pid)
			free(data->pid);
		if (data->path_variable)
			free(data->path_variable);
		free(data);
	}
	exit(errno);
}

void	free_cmd(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->cmd_count)
	{
		if (data->cmd[i].command)
			free(data->cmd[i].command);
		if (data->cmd[i].options)
		{
			j = 0;
			while (data->cmd[i].options[j])
			{
				free(data->cmd[i].options[j]);
				j++;
			}
			free(data->cmd[i].options);
		}
		i++;
	}
	free(data->cmd);
}

void	close_files(t_data *data)
{
	if (data->fd_in > 0)
		close(data->fd_in);
	if (data->fd_out > 0)
		close(data->fd_out);
}

void	error_msg(char *prefix, char *suffix)
{
	if (prefix && !suffix)
		perror(prefix);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (!suffix)
			write(2, "\n", 1);
		ft_putendl_fd(suffix, STDERR_FILENO);
	}
}

void	close_pipes(t_data *data)
{
	if (data->pipe[0] > 0)
		close(data->pipe[0]);
	if (data->pipe[1] > 0)
		close(data->pipe[1]);
	close_files(data);
}
