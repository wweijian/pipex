/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:09:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/14 15:15:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_argument (int ac, char **av, char **envp, t_data *data)
{
	check_heredoc(av, data);
	if ((data->heredoc.fd < 0 && ac < 4) || (data->heredoc.fd >= 0 && ac < 6))
		error_msg("not enough arguments", data);
	check_envp(ac, envp, data);
	if (data->heredoc.fd < 0)
		check_filein(av, data);
	check_fileout(ac, av, data);
}

void	check_envp(int ac, char **envp, t_data *data)
{
	data->cmd_count = ac - 3;
	if (data->heredoc.fd >= 0)
		data->cmd_count--;
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5) && *envp[6] != 0)
		{
			data->envp = ft_substr(*envp, 6, ft_strlen(*envp));
			split_directories(data);
			return ;
		}
		envp++;
	}
	error_msg("no \"PATH=\ variable found", data);
}

void	check_heredoc(char **av, t_data *data)
{
	if (ft_strncmp(av[1], "here_doc", 9))
	{
		data->heredoc.fd = open(av[1], O_RDONLY);
		if (data->heredoc.fd == -1)
			error_msg("error parsing here_doc", data);
		if (av[2])
			data->heredoc.limiter = ft_strdup(av[2]);
	}
	else
		data->heredoc.fd = -2048;
}

void	check_filein(char** av, t_data *data)
{
	data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in < 0)
		error_msg("error handling input file", data);	
}

void	check_fileout(int ac, char **av, t_data *data)
{
	if (data->heredoc.fd > 0)
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 664);
	else
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 664);
	if (data->fd_in < 0)
		error_msg("error handling input file", data);
}