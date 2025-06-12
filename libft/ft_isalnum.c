/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:06 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 16:02:05 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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
	for (char a = '!'; a <= '}'; a++)
	{
		printf("a: %c\n", a);
		printf("   ft_isalnum: %d\n", ft_isalnum(a));
		printf("   ctype isalnum: %d\n", isalnum(a));
		if (ft_isalnum(a) - isalnum(a) != 0)
		{
			printf("ERROR\n");
			break;
		}
	}
} */