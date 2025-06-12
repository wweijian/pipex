/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 19:26:05 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	- mod to get last number (put front of string)
*/

#include "libft.h"

static int	is_neg(int num)
{
	if (num < 0)
		return (-1);
	return (1);
}

static int	numlen(int n, int neg)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (neg == -1)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int				neg;
	int				len;
	unsigned int	num;
	char			*res;

	neg = is_neg(n);
	num = (unsigned int) n * neg;
	len = numlen(num, neg);
	res = (char *) malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		res[len - 1] = num % 10 + '0';
		num = num / 10;
		if (len == 1 && neg == -1)
			res[0] = '-';
		len--;
	}
	return (res);
}

/* #include <limits.h>
#include <stdio.h>

int main ()
{
	char *s_max = ft_itoa(INT_MAX);
	char *s_mid = ft_itoa(123123);
	char *s_min = ft_itoa(INT_MIN);
	char *s_all = ft_itoa(-1234567890);
	char *s_zero = ft_itoa(0);
	char *s_negzero = ft_itoa(-0);

	printf("int max:\t%s\t\n", s_max);
	printf("int mid:\t%s\t\n", s_mid);
	printf("int min:\t%s\t\n", s_min);
	printf("int all:\t%s\t\n", s_all);
	printf("int zero:\t%s\t\n", s_zero);
	printf("int zero:\t%s\t\n", s_negzero);
	

	free (s_max);
	free (s_mid);
	free (s_min);
	free (s_all);
	free (s_negzero);
} */