/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:16:51 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 13:36:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_BONUS_H
# define GNL_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* ------------- Main function ------------- */
char	*get_next_line(int fd, char *lim);

/* --------------- Utilities --------------- */
char	*gnl_strdup(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char const *s2);

#endif