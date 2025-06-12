/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:56:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/09 23:49:23 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main ()
{
	ft_putchar_fd('1', 0);
	write(1, "\n", 1);
	ft_putchar_fd('1', 1);
	write(1, "\n", 1);
	ft_putchar_fd('1', 2);
	write(1, "\n", 1);
} */