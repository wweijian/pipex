/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:11:32 by weijian           #+#    #+#             */
/*   Updated: 2025/06/22 11:00:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_filein(char **av, t_data *data)
{
	data->fd_in = open(av[1], O_RDONLY);
	if (data->fd_in < 0 || !*av[1])
	{
		error_msg(NULL, av[1]);
		data->fd_in = open("/dev/null", O_RDONLY);
	}
}

void	check_fileout(int ac, char **av, t_data *data)
{
	data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_out < 0)
	{
		error_msg(NULL, av[ac - 1]);
		close_files(data);
		free_and_exit(data);
	}
}
