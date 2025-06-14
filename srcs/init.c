/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:37:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/14 15:12:57 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data (int ac, char **av, char **envp, t_data *data)
{
	data = default_init();
	validate_argument(ac, av, envp, data);
	make_pipe(ac, av, data);
	make_cmd(ac, av, data);
}

void	make_pipe (int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->pipe = malloc(sizeof(*(data->pipe)) * 2 * (data->cmd_count - 1));
	while (i < data->cmd_count - 1)
	{
		if(pipe(data->pipe + 2 * i) == -1)
			error_msg("pipe failed to initialize", data);
		i++;
	}
}

t_data	*default_init(void)
{
	t_data *data;
	
	data = malloc(sizeof(*data));
	if (!data)
		error_msg("initialization failed", data);
	data->heredoc.fd = -1;
	data->heredoc.limiter = NULL;
	data->fd_in = -1;
	data->fd_out -1;
	*data->pipe = NULL;
	data->cmd_count = 0;
}

void	make_cmd(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (data->heredoc.fd >= 0)
		i++;
	data->cmd = malloc(sizeof(*data->cmd) * data->cmd_count);
	while (i < ac - 2)
	{
		data->cmd[j].command = av[i];
		i++;
		j++;
	}
}
