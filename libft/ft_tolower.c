/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:16:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/07 00:07:46 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (c - 'A' + 'a');
	else
		return (c);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	main()
{
	for (char a = 'A'; a <= 'z'; a++)
	{
		printf("letter: %c   ft_tolower: %c   tolower:%c\n",
			a, ft_tolower(a), tolower(a));
	}
} */