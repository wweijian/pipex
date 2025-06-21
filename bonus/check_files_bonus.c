/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:11:32 by weijian           #+#    #+#             */
/*   Updated: 2025/06/21 16:51:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_filein(char **av, t_data *data)
{
	if (data->heredoc > 0)
		data->fd_in = open_heredoc(av);
	else
		data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in < 0 || !*av[1])
	{
		error_msg(NULL, av[1]);
		data->fd_in = open("/dev/null", O_RDONLY);
	}
}

void	check_fileout(int ac, char **av, t_data *data)
{
	if (data->heredoc > 0)
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_out < 0)
	{
		error_msg(NULL, av[ac - 1]);
		free_and_exit(data);
	}
}

int	open_heredoc(char **av)
{
	int		temp_fd;
	char	*line;

	temp_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (temp_fd == -1)
		error_msg(NULL, ".heredoc");
	while (1)
	{
		ft_putstr_fd("heredoc > ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO, av[2]);
		if (!line)
			break ;
		else if (!ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& *(line + ft_strlen(av[2])) == '\n')
			break ;
		else
			ft_putstr_fd(line, temp_fd);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	close(temp_fd);
	return (open(".heredoc", O_RDONLY));
}
