/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:05:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/22 20:02:52 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = init_data(ac, av, envp);
	ft_pipe(data);
	close_files(data);
	if (data)
	{
		if (data->cmd)
			free_cmd(data);
		if (data->pid)
			free(data->pid);
		if (data->path_variable)
			free(data->path_variable);
		free(data);
	}
	return (0);
}
