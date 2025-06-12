/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:12:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 17:46:14 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	res_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	src = (char *)s + start;
	res_len = len + 1;
	if (ft_strlen(src) < len)
		res_len = ft_strlen(src) + 1;
	res = (char *) malloc(sizeof(char) * res_len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, res_len);
	return (res);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char			*s = strdup("I am Groot.");
	unsigned int	start = 5;
	size_t			len = 7;
	char			*res =  ft_substr(s,start,len)
	printf("resulting string: %s\n", res);
	free(res);
	
}
 */