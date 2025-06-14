/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:50:40 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/08 14:44:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (1);
	else
		return (0);
}
