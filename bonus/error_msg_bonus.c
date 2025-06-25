/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:49:06 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/22 11:15:23 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_msg(char *prefix, char *suffix)
{
	if (prefix && !suffix)
		perror(prefix);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (!suffix)
			write(2, "\n", 1);
		ft_putendl_fd(suffix, STDERR_FILENO);
	}
}
