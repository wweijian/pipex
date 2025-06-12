/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:47:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/12 17:45:05 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
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

	// declaration and assign of pointers
	void *p1 = &a;
	void *p2 = &b;
	void *p3 = &c;
	void *p4 = &d;

	// Creation of List Elements
	head = ft_lstnew(p1);
	head->next = ft_lstnew(p2);
	head->next->next = ft_lstnew(p3);

	printf("Linked list before:\n");
	print_list(head);

	// Insert a new element at the beginning of the linked list
	ft_lstadd_front(&head, ft_lstnew(p4));

	printf("\nLinked list after:\n");
	print_list(head);

	// free of memory allocated
	free(head);
} */