/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:14:26 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/07 00:07:35 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!src || !dst) && !size)
		return (0);
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	while (src[j])
		j++;
	if (i < size)
		dst[i + j] = '\0';
	return (i + j);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char *dst;
	char *src;
	char *dst2;
	char *src2;
	int	size;

	dst = strdup("aasdasdasdasasdasdasd");
	src = strdup("aasdasdasdasdasda");
	dst2 = strdup(dst);
	src2 = strdup(src);
	size = 10;

	printf("---\n");
	printf("old: %s   %s\n", dst, src);
	printf("ft_strlcat    %ld\n", ft_strlcat(dst,src,size));
	printf("new: %s   %s\n\n", dst, src);
	printf("---\n");
	printf("old: %s   %s\n", dst2, src2);
	printf("strlcat    %ld\n", strlcat(dst2,src2,size));
	printf("new: %s   %s\n", dst2, src2);
}
 */