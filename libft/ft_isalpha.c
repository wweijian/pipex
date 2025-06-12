/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:37:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/06 15:16:47 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	main()
{
	for (char a = 'A'; a <= 'z'; a++)
	{
		printf("a: %c\n", a);
		printf("ft_isalpha: %d\n", ft_isalpha(a));
		printf("ctype isalpha: %d\n", isalpha(a));
		if (ft_isalpha(a) - isalpha(a) != 0)
			break;
		if (a == 'z')
			printf("done\n");
	}
} */