/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:09:37 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 19:24:40 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*buf;
	size_t			total_size;

	total_size = nmemb * size;
	if (size > 0 && nmemb > 18446744073709551615UL / size)
		return (NULL);
	res = (void *)malloc(total_size);
	if (!res)
		return (0);
	buf = (unsigned char *)res;
	while (total_size != 0)
	{
		*buf = '\0';
		buf++;
		total_size--;
	}
	return (res);
}

/* #include <stdio.h>

int main(void)
{
	size_t	nmemb = 10;
	size_t	size = 10;
	void	*ptr = ft_calloc(nmemb, size);
	unsigned char	*buf = (unsigned char *)ptr;

	for(unsigned long i = 0; i < nmemb * size;i++)
	{
		if (buf[i] != '\0')
		{
			printf("non null error");
			break;
		}
		
	}

	printf("OKAY\n");
	free(ptr);
} */