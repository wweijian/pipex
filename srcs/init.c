/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/17 10:43:29 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*init_data (int ac, char **av, char **envp)
{
	char	**paths;
	t_data	*data;
	
	data = default_init(envp);
	validate_argument(ac, av, envp, data);
	data->pipe = make_pipe(data);
	paths = split_paths(data->path_variable);
	make_cmd(ac, av, paths, data);
	return (data);
}

int	*make_pipe (t_data *data)
{
	int	i;

	i = 0;
	data->pipe = malloc(sizeof(*(data->pipe)) * 2 * (data->cmd_count - 1));
	printf("valid pipes:  ");
	while (i < data->cmd_count - 1)
	{
		if(pipe(data->pipe + 2 * i) == -1)
			error_msg("pipe failed to initialize", data);
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
	data->pipe = NULL;
	data->cmd_count = 0;
	return (data);
}

/* 
	printf("printing paths:\n\n");
	for (int i = 0; paths[i]; i++)
		printf("%d:  %s \n",i, paths[i]);
*/