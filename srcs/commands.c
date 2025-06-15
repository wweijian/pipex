/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:21:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/15 17:38:51 by wjhoe            ###   ########.fr       */
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
	while (i < ac - 2)
	{
		temp = ft_split(av[i], ' ');
		data->cmd[j].command = get_cmd_path(temp[i], paths);
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

	i = 1;
	while (temp[i])
	{
		options[i - 1] = temp[i];
		i++;
	}
	return (options);

}

char	*get_command_path(char *command)
{
	char	*command_path;
	
	if (!access(command, F_OK | X_OK))
		return(ft_strdup(command));
	
}