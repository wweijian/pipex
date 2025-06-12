/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:01:42 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/15 14:34:18 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	res = (char *) malloc (sizeof(char) * (len + 1));
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char *s0 = strdup("nihao");
	char *s1 = ft_strdup(s0);
	printf("s1: %s\n", s1);
} */