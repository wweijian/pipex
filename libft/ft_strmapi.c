/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:24:25 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 17:43:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}

/* char	ft_transpose(unsigned int i, char c)
{
	if (c == 'z' || c == 'Z')
		c = c - 26 + i;
	else
		c = c + i;
	return (c);
}

#include <stdio.h>
int main ()
{
	char	*s = ft_strdup("QWERTYUIOPASDFGHJKLZXCVBNM");
	printf("before: %s\n", s);
	char	*t = ft_strmapi(s, ft_transpose);
	printf("after:  %s\n", t);
	free (s);
	free (t);
} */