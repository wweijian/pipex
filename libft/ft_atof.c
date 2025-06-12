/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:13:21 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 13:27:43 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_neg(char c, int *index)
{
	if (c == '+' || c == '-')
	{
		(*index)++;
		if (c == '-')
			return (-1);
	}
	return (1);
}

static int	move_space(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

double	ft_atof(char *s)
{
	int		i;
	double	nb;
	int		neg;
	double	dec;

	i = 0;
	nb = 0;
	neg = 1;
	dec = 0.1;
	i = move_space(s);
	neg = check_neg(s[i], &i);
	while (s[i] && ft_isdigit(s[i]) && s[i] != '.')
	{
		nb = (nb * 10.0) + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		nb = nb + (s[i] - '0') * dec;
		dec *= 0.1;
		i++;
	}
	return (nb * neg);
}
