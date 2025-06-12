/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:17 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 23:43:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buf;
	unsigned char	ch;

	buf = (unsigned char *)s;
	ch = c;
	while (n--)
	{
		*buf = ch;
		buf++;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = strdup("asad");
	char *s1a = strdup(s1);
	int size = 1;
	char replace = 'x';

	printf("original: %s\n", s1);
	ft_memset(s1, replace, size);
	printf("ft_memset: %s\n", s1);
	memset(s1a, replace, size);
	printf("memset:    %s\n", s1a);
} */