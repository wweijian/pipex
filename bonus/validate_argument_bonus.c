/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:09:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 16:51:51 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	validate_argument(int ac, char **av, char **envp, t_data *data)
{
	if (ac < 5)
	{
		ft_putstr_fd("usage: ./pipex infile cmd1 cmd2 ..,", STDERR_FILENO);
		ft_putstr_fd("cmdn outfile or here_doc ", STDERR_FILENO);
		ft_putendl_fd("LIMITER cmd1 cmd2 .. cmdn outfile", STDERR_FILENO);
		free_and_exit(data);
	}
	check_heredoc(av, data);
	if ((data->heredoc > 0 && ac < 6))
	{
		ft_putstr_fd("usage: ./pipex infile cmd1 cmd2 ..,", STDERR_FILENO);
		ft_putstr_fd("cmdn outfile or here_doc ", STDERR_FILENO);
		ft_putendl_fd("LIMITER cmd1 cmd2 .. cmdn outfile", STDERR_FILENO);
		free_and_exit(data);
	}
	check_envp(ac, envp, data);
	check_filein(av, data);
	check_fileout(ac, av, data);
}

void	check_envp(int ac, char **envp, t_data *data)
{
	int	i;

	i = 0;
	data->cmd_count = ac - 3;
	if (data->heredoc > 0)
		data->cmd_count--;
	if (!envp || !*envp)
	{
		data->path_variable = ft_strdup("");
		return ;
	}
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5) && envp[i][6] != 0)
		{
			data->path_variable = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			return ;
		}
		i++;
	}
	data->path_variable = ft_strdup("");
}

void	check_heredoc(char **av, t_data *data)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		data->heredoc = 1;
	}
	else
		data->heredoc = 0;
}
