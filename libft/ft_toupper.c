/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:10:43 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/07 00:07:24 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 'a' + 'A');
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
		printf("letter: %c   ft_toupper: %c   toupper:%c\n",
			a, ft_toupper(a), toupper(a));
	}
} */