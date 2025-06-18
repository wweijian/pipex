/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/18 14:40:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*init_data (int ac, char **av, char **envp)
{
	char	**paths;
	t_data	*data;
	
	data = default_init(envp);
	validate_argument(ac, av, envp, data);
	paths = split_paths(data->path_variable);
	make_cmd(ac, av, paths, data);
	return (data);
}

t_data	*default_init(char** envp)
{
	t_data *data;
	
	data = malloc(sizeof(*data));
	if (!data)
		error_msg("initialization failed", data);
	data->heredoc = 0;
	data->envp = envp;
	data->cmd_count = 0;
	return (data);
}

/* 
	printf("printing paths:\n\n");
	for (int i = 0; paths[i]; i++)
		printf("%d:  %s \n",i, paths[i]);
*/