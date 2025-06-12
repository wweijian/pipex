/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:05:54 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/08 10:24:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char *negwspace = strdup("      -1234");
	char *pluswspace = strdup("      +1234");
	char *poswspace = strdup("       1234");
	char *neg = strdup("-1234");
	char *pos = strdup("1234");
	char *plus = strdup("+1234");
	char *let = strdup("aa1234");
	char *multsign = strdup("+-1234");
	char *eqsign = strdup("=1234");

	if(ft_atoi(negwspace) == atoi(negwspace))
		printf("1     negwspace\t\t\tOKAY\n");
	if(ft_atoi(pluswspace) == atoi(pluswspace))
		printf("2     pluswspace\t\tOKAY\n");
	if(ft_atoi(poswspace) == atoi(poswspace))
		printf("3     poswspace\t\t\tOKAY\n");
	if(ft_atoi(neg) == atoi(neg))
		printf("4     neg\t\t\tOKAY\n");
	if(ft_atoi(pos) == atoi(pos))
		printf("5     pos\t\t\tOKAY\n");
	if(ft_atoi(plus) == atoi(plus))
		printf("6     plus\t\t\tOKAY\n");
	if(ft_atoi(let) == atoi(let))
		printf("7     let\t\t\tOKAY\n");
	if(ft_atoi(multsign) == atoi(multsign))
		printf("8     multsign\t\t\tOKAY\n");
	if(ft_atoi(eqsign) == atoi(eqsign))
		printf("9     eqsign\t\t\tOKAY\n");
} */