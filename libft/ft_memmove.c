/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:08:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 16:11:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destbuf;
	const char	*srcbuf;

	if (src == dest)
		return (dest);
	destbuf = (char *)dest;
	srcbuf = (const char *)src;
	if (srcbuf < destbuf && srcbuf + n > destbuf)
		while (n--)
			*(destbuf + n) = *(srcbuf + n);
	else
	{
		while (n--)
		{
			*destbuf = *srcbuf;
			srcbuf++;
			destbuf++;
		}
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = strdup("asdddad");
	char *s1a = strdup(s1);
	// char *s2 = strdup("y12323123123");
	// char *s2a = strdup(s2);
	int size = 59;


	printf("original: %s\n", s1);
	ft_memmove(&s1[0], &s1[1], size);
	printf("ft_memmove: %s\n", s1);
	memmove(&s1a[0], &s1a[1], size);
	printf("memmove:    %s\n", s1a);
	printf("strcmp: %d\n",strcmp(s1,s1a));

	free (s1);
	free (s1a);
} */