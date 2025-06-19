/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 20:20:29 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(t_data *data)
{
	int		child;

	child = 0;
	data->pid = ft_calloc(data->cmd_count, sizeof(*(data->pid)));
	if (!data->pid)
	{
		error_msg("malloc failure", NULL);
		free_and_exit(data);
	}
	dup2(data->fd_in, STDIN_FILENO);
	while (child < data->cmd_count)
	{
		create_process(data, child);
		child++;
	}
	return (check_exit_status(data));
}

void	create_process(t_data *data, int i)
{
	pid_t	pid;

	if (pipe(data->pipe) == -1)
		error_msg("error making pipe", NULL);
	pid = fork();
	if (pid == -1)
		error_msg("fork process failed", NULL);
	if (pid == 0)
	{
		close(data->pipe[0]);
		if (i == data->cmd_count - 1)
			dup2(data->fd_out, STDOUT_FILENO);
		else
			dup2(data->pipe[1], STDOUT_FILENO);
		if (execve(data->cmd[i].command, data->cmd[i].options, data->envp)
			== -1)
		{
			error_msg(NULL, data->cmd[i].options[0]);
			free_and_exit(data);
		}
	}
	close(data->pipe[1]);
	dup2(data->pipe[0], STDIN_FILENO);
	data->pid[i] = pid;
}

int	check_exit_status(t_data *data)
{
	pid_t	wpid;
	int		exit_code;
	int		status;
	int		i;

	exit_code = 5;
	i = 0;
	while (i < data->cmd_count)
	{
		wpid = waitpid(data->pid[i], &status, 0);
		if (wpid == data->pid[data->cmd_count - 1])
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		i++;
	}
	return (exit_code);
}
