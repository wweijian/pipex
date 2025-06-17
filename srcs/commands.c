/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:21:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/16 19:04:44 by weijian          ###   ########.fr       */
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
	if (data->heredoc.fd >= 0)
		i++;
	data->cmd = malloc(sizeof(*data->cmd) * data->cmd_count);
	while (i < ac - 1)
	{
		temp = ft_split(av[i], ' ');
		data->cmd[j].command = get_cmd_path(temp[0], paths, data);
		data->cmd[j].options = get_cmd_options(temp);
		data->cmd[j].pid = 0;
		i++;
		j++;
		free(temp);
	}
}

char	**get_cmd_options(char** temp)
{
	int		i;
	char	**options;

	i = count_options(temp);
	options = ft_calloc(i, sizeof(*options));
	while (i >= 0)
	{
		options[i] = temp[i];
		i--;
	}
	return (options);
}

char	*get_cmd_path(char *command, char **paths, t_data *data)
{
	int		i;
	char	*command_path;
	
	if (!access(command, F_OK | X_OK))
		return(ft_strdup(command));
	i = 0;
	while (paths[i])
	{
		// might need to check if i need to add a "/"
		command_path = ft_strjoin(paths[i], command);
		if (!access(command_path, F_OK | X_OK))
		{
			printf("%s \n", command_path); // this prints out the right command path
			return (command_path);
		}
		i++;
		free(command_path);
	}
	error_msg("command path missing", data);
	return (NULL);
}

int	count_options(char** temp)
{
	int	res;

	res = 0;
	while (temp[res])
		res++;
	return (res);
}