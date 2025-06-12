/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:30:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 13:26:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src && !n)
		return (0);
	if (find == NULL || find == src)
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == find[j] && (i + j) < n)
		{
			if (src[i + j] == '\0' && find[j] == '\0')
				return ((char *)&src[i]);
			j++;
		}
		if (find[j] == '\0')
			return ((char *)(src + i));
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char	*src = strdup("qwertyuiopasdfghjklzxcvbnm");
	char	*find = strdup("dfghjklzx");
	char	*nofind = strdup("dfghjklx");
	char	*empty = strdup("");
	size_t	len	= 0;

	for (len = 0; len < strlen(src); len++)
	{
		printf("size: %zu     \n", len);
		printf("find: find\nft_strncmp: %s\n   strnstr: %s\n\n", 
				ft_strnstr(src,find,len),strnstr(src,find,len));
		printf("find: nofind\nft_strncmp: %s\n   strnstr: %s\n\n", 
				ft_strnstr(src,nofind,len),strnstr(src,nofind,len));
		printf("find: empty\nft_strncmp: %s\n   strnstr: %s\n\n", 
				ft_strnstr(src,empty,len),strnstr(src,empty,len));
		printf("----\n");
	}

	free (src);
	free (find);
	free (nofind);
	free (empty);

} */