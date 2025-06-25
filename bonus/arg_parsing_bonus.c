/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:51:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/21 16:51:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*remove_single_quotes(char *str)
{
	int		i;
	char	*res;

	if (!str || !*str)
		return (str);
	i = 0;
	res = str;
	if (str[i] == '\'' && str[ft_strlen(str) - 1] == '\'')
	{
		res = ft_strtrim(str, "\'");
		free(str);
	}
	res = remove_internal_quotes(res);
	return (res);
}

char	*remove_internal_quotes(char *str)
{
	char	*open_quote;
	char	*close_quote;
	char	*res;

	open_quote = ft_strchr(str, '\'');
	if (!open_quote)
		return (str);
	close_quote = ft_strchr(open_quote + 1, '\'');
	if (!close_quote)
		return (str);
	res = replace_char(str, '\'');
	return (remove_internal_quotes(res));
}

char	*replace_char(char *str, char c)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (str[i] && count < 2)
	{
		if (str[i] == c)
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
			count++;
		}
		i++;
	}
	res = ft_strdup(str);
	free(str);
	return (res);
}
