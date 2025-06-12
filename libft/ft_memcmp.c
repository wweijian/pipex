/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:08:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:53:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1buf;
	const char	*s2buf;
	size_t		i;

	if (n == 0)
		return (0);
	s1buf = (const char *)s1;
	s2buf = (const char *)s2;
	i = 0;
	while ((i < n - 1) && s1buf[i] == s2buf[i])
		i++;
	return ((unsigned char)s1buf[i] - (unsigned char)s2buf[i]);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = strdup("asdddad");
	char *s1a = strdup(s1);
	char *s2 = strdup("x");
	int size = 1;

	printf("original: %s\n", s1);
	printf("s1: %s, s2: %s\n", s1, s2);
	printf("ft_memcmp: %d\nmemcmp:   %d\n",ft_memcmp(s1, s2, size),
		memcmp(s1, s2, size));
	printf("\n");
	printf("s1: %s, s2: %s\n", s1, s1a);
	printf("ft_memcmp: %d\nmemcmp:   %d\n",ft_memcmp(s1, s1a, size),
		memcmp(s1, s1a, size));
	free(s1);
	free(s1a);
	free(s2);
} */