/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:11:32 by weijian           #+#    #+#             */
/*   Updated: 2025/06/18 15:57:50 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_filein(char** av, t_data *data)
{
	if (data->heredoc > 0)
		open_heredoc(data, av[2]);
	else
		data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in < 0)
		data->fd_in = open("/dev/null", O_RDONLY);
}

void	check_fileout(int ac, char **av, t_data *data)
{
	if (data->heredoc > 0) // ya okay i might not want to open it until work  needs to be done
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_out < 0)
		error_msg("error handling output file", data);
}

void	open_heredoc(t_data *data, char *limiter)
{
	char	*line;

	data->fd_in = open(".heredoc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->fd_in == -1)
		error_msg("error accessing heredoc", data);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
			break ;
		else
			ft_putstr_fd(line, data->fd_in);
		free(line);
	}
	if (line)
		free(line);
}
