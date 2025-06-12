/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:44:20 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 19:24:29 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)s;
	while (n != 0)
	{
		*buf = '\0';
		buf++;
		n--;
	}
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = strdup("asldjkasldkjaslkdj");
	char *s1a = strdup(s1);
	int size = 6;
	int count = 0;
	int len = strlen(s1);
	
	printf("original: %s\n", s1);
	ft_bzero(s1, size);
	printf("ft_memset:\n---\n");
	while (count < len)
	{
		printf("s1[%d]: %c\n", count, s1[count]);
		count++;
	}
	printf("---\n");
	count = 0;
	bzero(s1a, size);
	printf("memset:\n---\n");
	while (count < len)
	{
		printf("s1[%d]: %c\n", count, s1a[count]);
		count++;
	}
} */