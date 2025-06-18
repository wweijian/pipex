/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/18 08:26:40 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe (t_data *data)
{
	int	child;

	child = 0;
	dup2(data->fd_in, STDIN_FILENO);
	while (child < data->cmd_count)
	{
		if (pipe(data->pipe) == -1)
			error_msg("error making pipe", data);
		data->cmd[child].pid = fork();
		if (data->cmd[child].pid == -1)
			return(error_msg("fork process failed", data));
		if (data->cmd[child].pid == 0)
			execute_child_process(data, child);
		child++;
	}
	close_files(data);
	check_exit_status(data, child - 1);
}

void	execute_child_process(t_data *data, int child)
{
	close(data->pipe[0])
	dup2
}

void	execute_command(int input_fd, int output_fd, t_data *data, int child)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		error_msg("failed to redirect command", data);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		error_msg("failed to redirect command", data);
	close_files(data);
	if (execve(data->cmd[child].command, data->cmd[child].options, data->envp) == -1)
		error_msg("shell command cannot be executed", data);
}

int	check_exit_status(t_data *data, int child)
{
	pid_t	wpid;
	int		exit_code;
	int		status;

	exit_code = 1;
	printf("children: %d\n", child);
	while (child >= 0)
	{
		printf("[CES] data->cmd[child].pid %d\n", data->cmd[child].pid);
		wpid = waitpid(data->cmd[child].pid, &status, 0);
		if (wpid == -1)
			error_msg("waitpid failed", data);
		if (wpid == data->cmd[data->cmd_count - 1].pid)
		{
			if(WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		child--;
	}
	return(exit_code);
}
