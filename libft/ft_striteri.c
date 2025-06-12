/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:44:46 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 17:27:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void	ft_transpose(unsigned int i, char *c)
{
	if (*c == 'z' || *c == 'Z')
		*c = *c - 26 + i;
	else
		*c = *c + i;
}

#include <stdio.h>
int main ()
{
	char	*s = ft_strdup("QWERTYUIOPASDFGHJKLZXCVBNM");
	printf("before: %s\n", s);
	ft_striteri(s, ft_transpose);
	printf("after:  %s\n", s);
	free (s);
} */