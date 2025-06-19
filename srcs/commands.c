/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:21:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/19 12:31:30 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_cmd(int ac, char **av, char **paths, t_data *data)
{
	int		i;
	int		j;
	char	**temp;

	i = 2;
	j = 0;
	if (data->heredoc > 0)
		i++;
	data->cmd = malloc(sizeof(*data->cmd) * data->cmd_count);
	while (i < ac - 1)
	{
		temp = ft_split(av[i], ' ');
		data->cmd[j].command = get_cmd_path(temp[0], paths);
		data->cmd[j].options = get_cmd_options(temp);
		i++;
		j++;
		free(temp);
	}
}

char	**get_cmd_options(char** temp)
{
	int		i;
	char	**options;

	if (!*temp)
		return (ft_calloc(0, sizeof(*temp)));
	i = 0;
	while (temp[i])
		i++;
	options = malloc(sizeof(*options) * (i + 1));
	options[i] = NULL;
	while (i >= 0)
	{
		options[i] = temp[i];
		options[i] = remove_single_quotes(options[i]);
		i--;
	}
	return (options);
}

char	*get_cmd_path(char *command, char **paths)
{
	int		i;
	char	*command_path;
	
	if (!command)
		return(ft_strdup(""));
	if (!access(command, F_OK | X_OK))
		return(ft_strdup(command));
	i = 0;
	while (paths[i])
	{
		command_path = ft_strjoin(paths[i], command);
		if (!access(command_path, F_OK | X_OK))
			return (command_path);
		i++;
		free(command_path);
	}
	return (ft_strdup(""));
}
