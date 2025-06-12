/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:00:12 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:49:11 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char	*s1 = strdup("qwertyuiopasdfghjklzxcvbnm");
	char	*s2 = strdup("qwertyuiopasdfg");
	size_t	size = 0;

	printf("s1: %s    s2: %s\n", s1, s2);
	for (size = 0; size < strlen(s1); size++)
	{
		printf("size: %zu    ", size);
		printf("ft_strncmp: %d    stncmp:  %d\n", 
			ft_strncmp(s1, s2, size), strncmp(s1, s2, size));
	}
	free(s1); 
	free(s2);
} */