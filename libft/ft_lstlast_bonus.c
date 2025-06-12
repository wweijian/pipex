/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:37:52 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/11 11:48:13 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	head->next->next->next = ft_lstnew(p4);

	printf("Linked list before:\n");
	print_list(head);

	head = ft_lstlast(head);
	printf("Last ");
	print_list(head);

	// free of memory allocated
	free(head);
} */