/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:41:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 21:29:22 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size > 0)
	{
		while (j < (size - 1) && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char *s1;
	char *s2;
	char *s1a;
	char *s2a;
	int	size;

	s1 = strdup("asdassdasda");
	s2 = strdup("asldjklasdlkajslajkds");
	s1a = strdup(s1);
	s2a = strdup(s2);
	size = 50;

	printf("---\n");
	printf("old: %s   %s\n", s1, s2);
	printf("strlcpy    %ld\n", ft_strlcpy(s1,s2,size));
	printf("new: %s   %s\n\n", s1, s2);
	printf("---\n");
	printf("old: %s   %s\n", s1a, s2a);
	printf("strlcpy    %ld\n", strlcpy(s1a,s2a,size));
	printf("new: %s   %s\n", s1a, s2a);

}
 */