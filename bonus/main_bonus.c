/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:05:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 17:02:23 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_status;

	data = init_data(ac, av, envp);
	exit_status = ft_pipe(data);
	free_and_exit(data);
	return (exit_status);
}
