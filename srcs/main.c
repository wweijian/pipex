/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:05:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/18 15:51:19 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char **envp)
{
	t_data	*data;
	
	data = init_data(ac, av, envp);
	ft_pipe(data);
}

// not invalidate a bad command 
// if i cannot access the file, i can open devnull