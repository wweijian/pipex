/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:07:00 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/17 16:41:24 by wjhoe            ###   ########.fr       */
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
# include "gnl_bonus.h"

typedef struct s_heredoc
{
	int		fd;
	char	*limiter;
}				t_heredoc;

typedef struct s_commands
{	
	char		*command;
	char		**options;
	int			pid;
}					t_commands;

typedef struct s_data
{
	t_commands	*cmd;
	int			cmd_count;
	t_heredoc	heredoc;
	char		**envp;
	char		*path_variable;
	int			fd_in;
	int			fd_out;
	int			*pipe;
}				t_data;

t_data	*init_data (int ac, char **av, char **envp);
int		*make_pipe (t_data *data);
t_data	*default_init(char** envp);

void	make_cmd(int ac, char **av, char **paths, t_data *data);
char	**get_cmd_options(char** temp);
char	*get_cmd_path(char *command, char **paths, t_data *data);
int		count_options(char** temp);


void	error_msg(char *msg, t_data *data);
void	free_and_exit(t_data *data);
void	close_pipe (t_data *data);
void	close_files (t_data *data);

char	**split_paths(char *path_variable);

void	validate_argument (int ac, char **av, char **envp, t_data *data);
void	check_envp(int ac, char **envp, t_data *data);
void	check_heredoc(char **av, t_data *data);
void	check_filein(char** av, t_data *data);
void	check_fileout(int ac, char **av, t_data *data);

void	ft_pipe (t_data *data);
void	execute_child_process(t_data *data, int child);
void	execute_command(int input_fd, int output_fd, t_data *data, int child);
int		check_exit_status(t_data *data, int child);

void	open_heredoc(t_data *data);



#endif

/* 
	Allowed functions: 
		open, close, read, write,
		malloc, free, perror,
		strerror, access, dup, dup2,
		execve, exit, fork, pipe,
		unlink, wait, waitpid
*/