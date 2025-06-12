/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:59:08 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 18:19:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = ft_substr(s1, start, end - start);
	return (res);
}

/* #include <string.h>
#include <stdio.h>

int main ()
{
	char *s1 = strdup("qwertyuiopasdfghjklzxcvbnmertyl");
	// char *exist = strdup("asdfghjkl");
	// char *last = strdup("zxcvbnm");
	// char *first = strdup("qwerty");
	// char *noexist = strdup("aa");

	char *s1trim = ft_strtrim(s1,"qwerty");
	// char *existtrim = ft_strtrim(s1,exist);
	// char *lasttrim = ft_strtrim(s1,last);
	// char *firsttrim = ft_strtrim(s1,first);
	// char *noexisttrim = ft_strtrim(s1,noexist);

	printf("s1 : s1---------    %s\n", s1trim);
	// printf("s1 : exist------    %s\n", existtrim);
	// printf("s1 : last-------    %s\n", lasttrim);
	// printf("s1 : first------    %s\n", firsttrim);
	// printf("s1 : noexist----    %s\n", noexisttrim);

	free(s1);
	// free(exist);
	// free(last);
	// free(first);
	// free(noexist);
	// free(s1trim);
	// free(existtrim);
	// free(lasttrim);
	// free(firsttrim);
	// free(noexisttrim);

} */