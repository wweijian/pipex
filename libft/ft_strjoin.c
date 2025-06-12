/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:36:59 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/11 20:43:07 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (res);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char	*s1 = strdup("hello ");
	char	*s2 = strdup("world..");
	char	*res = ft_strjoin(s1, s2);

	printf("s1: %s, s2: %s\n\tft_strjoin:%s\n", s1, s2, res);
	free(s1);
	free(s2);
	free(res);
} */