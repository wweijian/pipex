/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:11:31 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 16:15:14 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	main()
{
	for (char a = 0; a <= 126; a++)
	{
		printf("a: %c    (%d)\n", a, a);
		printf("   ft_isprint: %d\n", ft_isprint(a));
		printf("   ctype isprint: %d\n", isprint(a));
		if (ft_isprint(a) - isprint(a) != 0)
		{
			printf("ERROR\n");
			break;
		}
	}
} */