/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:07:00 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/14 14:45:14 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

typedef struct s_heredoc
{
	int		fd;
	char	*limiter;
}				t_heredoc;

typedef struct s_commands
{	
	char		*command;
	char		*path;
	char		**options;
}					t_commands;

typedef struct s_data
{
	t_commands	*cmd;
	int			cmd_count;
	t_heredoc	heredoc;
	char		*envp;
	int			fd_in;
	int			fd_out;
	int			*pipe;
	int			*pid;
	int			child;
}				t_data;

#endif

/* 
	Allowed functions: 
		open, close, read, write,
		malloc, free, perror,
		strerror, access, dup, dup2,
		execve, exit, fork, pipe,
		unlink, wait, waitpid
*/