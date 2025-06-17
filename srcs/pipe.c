/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/16 21:38:55 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe (t_data *data)
{
	int	child;

	child = 0;
	while (child < data->cmd_count)
	{
		data->cmd[child].pid = fork();
		if(data->cmd[child].pid)
			printf("data->cmd[child].pid: %d\n",data->cmd[child].pid);
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
	if (!data->cmd[child].command || access(data->cmd[child].command, F_OK))
		error_msg("executable not found", data);
	if (child == 0)
		redirect_command(data->fd_in, data->pipe[1], data);
	else if (child == data->cmd_count - 1)
		redirect_command(data->pipe[2 * child - 2], data->fd_out, data);
	else
		redirect_command(data->pipe[2 * child - 2], data->pipe[2 * child + 1], data);
	close_files(data);
	if (execve(data->cmd[child].command, data->cmd[child].options, data->envp) == -1)
		error_msg("shell command cannot be executed", data);
}

void	redirect_command(int input_fd, int output_fd, t_data *data)
{
	printf("fd_in / out: %d   %d\n", input_fd, output_fd);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		error_msg("failed to redirect command", data);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		error_msg("failed to redirect command", data);	
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

/* 
	get_command_path:
		get the directories for all the executable
	
	we have gotten the envp through ft_substr in validate argument
	through which we want to split_directories

	split_directories:
		get the relevant executable path FROM the envp
	
	Then i should append with a '/'
	And the append with the function name
	
	how do i know which path is relevant to which function though?
	
*/

/* 
	what is the pipe function trying to do? 
*/