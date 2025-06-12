/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:17:35 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 16:00:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
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
	for (char a = '!'; a <= 'Z'; a++)
	{
		printf("a: %c\n", a);
		printf("ft_isdigit: %d\n", ft_isdigit(a));
		printf("ctype isdigit: %d\n", isdigit(a));
		if (ft_isdigit(a) - isdigit(a) != 0)
			break;
		if (a == 'Z')
			printf("done\n");
	}
} */