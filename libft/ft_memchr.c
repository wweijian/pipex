/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:41:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:49:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char	*s1 = strdup("helloc");
	char	search = 'c';

	printf("s1: %s, search: %c\n----\n", s1, search);
	for(unsigned int size = 0; size < 10 ;size++)
	{
		printf("size: %u\n", size);
		printf("ft_memchr: %p\nmemchar:   %p\n\n", 
			ft_memchr(s1,search,size), memchr(s1,search,size));
	}
	free (s1);
} */