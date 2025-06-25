/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:07:00 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/22 11:13:22 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"
# include "gnl_bonus.h"

typedef struct s_commands
{
	char		*command;
	char		**options;
}					t_commands;

typedef struct s_data
{
	t_commands	*cmd;
	int			cmd_count;
	int			heredoc;
	char		**envp;
	char		*path_variable;
	int			fd_in;
	int			fd_out;
	int			pipe[2];
	int			*pid;
}				t_data;

/* INIT.C */
t_data	*init_data(int ac, char **av, char **envp);
t_data	*default_init(char **envp);
void	free_paths(char **paths);
char	**split_paths(char *path_variable);

/* COMMANDS.C */
void	make_cmd(int ac, char **av, char **paths, t_data *data);
char	**get_cmd_options(char **temp);
char	*get_cmd_path(char *command, char **paths);

/* ARGS_PARSING.C */
char	*remove_single_quotes(char *str);
char	*remove_internal_quotes(char *str);
char	*replace_char(char *str, char c);

/* EXIT.C */
void	error_msg(char *prefix, char *suffix);
void	free_and_exit(t_data *data);
void	free_cmd(t_data *data);
void	close_files(t_data *data);
void	close_pipes(t_data *data);
void	close_dups(void);

/* VALIDATE_ARGUMENT.C */
void	validate_argument(int ac, char **av, char **envp, t_data *data);
void	check_envp(int ac, char **envp, t_data *data);
void	check_heredoc(char **av, t_data *data);

/* CHECK_FILES.c */
void	check_filein(char **av, t_data *data);
void	check_fileout(int ac, char **av, t_data *data);
int		open_heredoc(char **av);

/* PIPE.C */
int		ft_pipe(t_data *data);
void	create_process(t_data *data, int child);
void	execute_command(int input_fd, int output_fd, t_data *data);
int		check_exit_status(t_data *data);

#endif
