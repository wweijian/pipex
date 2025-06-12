/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:38:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:52:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char	*s1 = strdup("qwertyuiopasqwertyuiop
		asdfghjklzxcvbnmdfghjklzxcvbnm/.,';l");
	char	search = 'c';

	for (int i = 0; i < (int) strlen(s1); i++)
	{
		search = s1[i];
		search = s1[i];
		printf("s1: %s, search: (%c)        ", s1, search);
		if (ft_strrchr(s1,search) == strrchr(s1,search))
			printf("OKAY\n");
		else
		{
			printf("NOTOKAY");
			break;
		}
	}
	printf("-----\ncompleted:  ft_strrchr\n");
	free(s1);
} */