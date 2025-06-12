/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:18:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/11 21:42:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/* #include <stdio.h>

void	print_list(t_list *list)
{
	t_list *temp = list;

	while (temp != NULL)
	{
		printf("Value: %d\n", *(int *)temp->content);
		temp = temp->next;
	}
}

int main(void)
{
	t_list	*head = (t_list *)malloc(sizeof(t_list));

	// declaration of values
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 500;
	int e = 4231;

	// declaration and assign of pointers
	void *p1 = &a;
	void *p2 = &b;
	void *p3 = &c;
	void *p4 = &d;
	void *p5 = &e;

	// Creation of List Elements
	head = ft_lstnew(p1);
	head->next = ft_lstnew(p2);
	head->next->next = ft_lstnew(p3);
	head->next->next->next = ft_lstnew(p4);
	head->next->next->next->next = ft_lstnew(p5);

	printf("Linked list:\n");
	print_list(head);

	printf("\nsize:%d\n", ft_lstsize(head));

	// free of memory allocated
	free(head);
} */