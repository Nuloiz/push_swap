/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/07 15:36:42 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int current)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(struct s_node));
	if (!new)
		return (NULL);
	new->value = current;
	new->next = NULL;
	return (new);
}

static t_node	*add_node(t_node *head, int value)
{
	t_node	*temp;
	t_node	*p;

	temp = new_node(value);
	if (head == NULL)
		head = temp;
	else
	{
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
	return (head);
}

t_node	*linked_list_start(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < argc)
	{
		stack_a = add_node(stack_a, (int)ft_atoi(argv[i]));
		i++;
	}
	free_array(argv);
	return (stack_a);
}
