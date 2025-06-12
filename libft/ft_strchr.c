/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:18:48 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:55:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main ()
{
	char	*s1 = strdup("qwertyuiopasqwertyuiopa
		sdfghjklzxcvbnmdfghjklzxcvbnm/.,';l");
	char	search = 'c';
	for (int i = 0; i < (int) strlen(s1); i++)
	{
		search = s1[i];
		search = s1[i];
		printf("s1: %s, search: (%c)        ", s1, search);
		if (ft_strchr(s1,search) == strchr(s1,search))
			printf("OKAY\n");
		else
		{
			printf("NOTOKAY");
			break;
		}
	}
	printf("-----\ncompleted:  ft_strchr\n");
} */