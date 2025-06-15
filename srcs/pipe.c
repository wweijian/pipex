/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:09 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/15 17:40:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe (t_data *data)
{
	int	child;

	child = 0;
	while (child < data->cmd_count)
	{
		
	}
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