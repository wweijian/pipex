/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:35:04 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/16 15:29:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>

int	main (void)
{
	printf("ft_strlen-strlen -> %lu\n", ft_strlen("hello") - strlen("hello"));
	printf("ft_strlen-strlen -> %lu\n", ft_strlen("") - strlen(""));
	printf("ft_strlen-strlen -> %lu\n", ft_strlen("helasd   ") - 
		strlen("helasd   "));

}
 */