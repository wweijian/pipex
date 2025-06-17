/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:09:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/17 15:45:08 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_argument (int ac, char **av, char **envp, t_data *data)
{
	if (ac < 5)
		error_msg("not enough arguments", data);
	check_heredoc(av, data);
	if ((data->heredoc.fd >= 0 && ac < 6))
		error_msg("not enough arguments", data);
	check_envp(ac, envp, data);
	check_filein(av, data);
	check_fileout(ac, av, data);
}

void	check_envp(int ac, char **envp, t_data *data)
{
	int	i;

	i = 0;
	data->cmd_count = ac - 3;
	if (data->heredoc.fd == 1)
		data->cmd_count--;
	printf("cmd count: %d\n",data->cmd_count);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5) && envp[i][6] != 0)
		{
			data->path_variable = ft_substr(envp[i], 6, ft_strlen(envp[i]));
			return ;
		}
		i++;
	}
	error_msg("no \"PATH=\" variable found", data);
}

void	check_heredoc(char **av, t_data *data)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data->heredoc.fd = 1;
		if (av[2])
			data->heredoc.limiter = ft_strjoin(av[2],"\n");
	}
	else
		data->heredoc.fd = -2048;
}