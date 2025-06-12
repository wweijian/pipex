/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:52:28 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 12:06:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destbuf;
	const char	*srcbuf;

	if (!dest && !src)
		return (0);
	if (n == 0 || (dest == src))
		return (dest);
	destbuf = (char *)dest;
	srcbuf = (const char *)src;
	while (n != 0)
	{
		if (*destbuf != *srcbuf)
			*destbuf = *srcbuf;
		destbuf++;
		srcbuf++;
		n--;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = strdup("asdddad");
	char *s1a = strdup(s1);
	char *s2 = strdup("y");
	char *s2a = strdup(s2);
	int size = 2;


	printf("original: %s\n", s1);
	ft_memcpy(s1, s2, size);
	printf("ft_memcpy: %s\n", s1);
	memcpy(s1a, s2a, size);
	printf("memcpy:    %s\n", s1a);
	printf("strcmp: %d\n",strcmp(s1,s1a));
	free(s1);
	free(s1a);
	free(s2);
	free(s2a);

} */