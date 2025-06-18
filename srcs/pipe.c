/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/18 15:48:55 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe (t_data *data)
{
	int		child;
	
	child = 0;
	dup2(-1, STDIN_FILENO);
	while (child < data->cmd_count - 1)
	{
		create_process(data, child);
		child++;
	}
	dup2(data->fd_out, STDOUT_FILENO);
	if (execve(data->cmd[child].command, data->cmd[child].options, data->envp) == -1)
		error_msg("shell command cannot be executed", data);
}

void	create_process(t_data *data, int i)
{
	pid_t	pid;
	
	if (pipe(data->pipe) == -1)
		error_msg("error making pipe", data);
	pid = fork();
	if (pid == -1)
		return(error_msg("fork process failed", data));
	if (pid == 0)
	{
		close(data->pipe[0]);
		dup2(data->pipe[1], STDOUT_FILENO);
		
		if (execve(data->cmd[i].command, data->cmd[i].options, data->envp) == -1)
			error_msg("shell command cannot be executed", data);
	}
	close(data->pipe[1]);
	dup2(data->pipe[0], STDIN_FILENO);
	check_exit_status(data, i, pid);
}

int	check_exit_status(t_data *data, int child, pid_t pid)
{
	pid_t	wpid;
	int		exit_code;
	int		status;

	exit_code = 1;
	// printf("[CES] pid %d\n", pid);
	wpid = waitpid(pid, &status, 0);
	if (wpid == -1)
		error_msg("waitpid failed", data);
	if (child == data->cmd_count - 1)
	{
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
	}
	return(exit_code);
}

/* 
void	execute_child_process(t_data *data, int child)
{
	close(data->pipe[0]);
	dup2(data->pipe[1], STDOUT_FILENO);
	if (execve(data->cmd[child].command, data->cmd[child].options, data->envp) == -1)
		error_msg("shell command cannot be executed", data);
} */