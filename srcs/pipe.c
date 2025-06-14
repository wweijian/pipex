/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/14 15:26:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe (t_data *data)
{
	int	child;

	child = 0;
	while (child < data->cmds.count)
	{
		data->cmds.options = ft_split(data->cmds.command[child], ' ');
		if (!data->cmds.options)
			error_msg("malloc failure in program");
		data->cmds.path = get_command_path(data->cmds.command);
	}
}

char	*get_command_path(char *command)
{
	char	*command_path;
	
	if (!access(command, F_OK | X_OK))
		return(ft_strdup(command));
	
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