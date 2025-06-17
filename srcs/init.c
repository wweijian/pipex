/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/16 18:17:56 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*init_data (int ac, char **av, char **envp, t_data *data)
{
	char	**paths;
	
	data = default_init(envp);
	validate_argument(ac, av, envp, data);
	data->pipe = make_pipe(ac, av, data);
	paths = split_paths(data->path_variable);
	make_cmd(ac, av, paths, data);
	return (data);
}

int	*make_pipe (int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->pipe = malloc(sizeof(*(data->pipe)) * 2 * (data->cmd_count - 1));
	printf("valid pipes:  ");
	while (i < data->cmd_count - 1)
	{
		if(pipe(data->pipe + 2 * i) == -1)
			error_msg("pipe failed to initialize", data);
		printf("%d  %d  ", data->pipe[2*i], data->pipe[2*i + 1]);
		i++;
	}
	printf("\n\n");
	return (data->pipe);
}

t_data	*default_init(char** envp)
{
	t_data *data;
	
	data = malloc(sizeof(*data));
	if (!data)
		error_msg("initialization failed", data);
	data->heredoc.fd = -1;
	data->heredoc.limiter = NULL;
	data->envp = envp;
	// data->fd_in = -1;
	// data->fd_out -1;
	data->pipe = NULL;
	data->cmd_count = 0;
	return (data);
}

/* 
	printf("printing paths:\n\n");
	for (int i = 0; paths[i]; i++)
		printf("%d:  %s \n",i, paths[i]);
*/