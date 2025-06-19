/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 20:29:55 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*init_data(int ac, char **av, char **envp)
{
	char	**paths;
	t_data	*data;

	data = default_init(envp);
	validate_argument(ac, av, envp, data);
	paths = split_paths(data->path_variable);
	make_cmd(ac, av, paths, data);
	if (!data->cmd || !data->cmd->options || !data->cmd->command)
	{
		error_msg("malloc failure", NULL);
		free_and_exit(data);
	}
	free_paths(paths);
	return (data);
}

t_data	*default_init(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(*data));
	if (!data)
	{
		error_msg("initialization failed", NULL);
		free_and_exit(data);
	}
	data->envp = envp;
	return (data);
}

char	**split_paths(char *path_variable)
{
	char	**paths;
	int		i;
	char	*temp;

	i = 0;
	paths = ft_split(path_variable, ':');
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = temp;
		i++;
	}
	return (paths);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
