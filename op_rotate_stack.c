/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:32:37 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/06 16:26:21 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*rotate_first(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (*stack_a);
	first = *stack_a;
	second = first->next;
	last = first->next;
	while (last->next != NULL)
	{
		last = last->next;
	}
	first->next = NULL;
	last->next = first;
	*stack_a = second;
	return (*stack_a);
}

t_node	*rotate_last(t_node **stack_a)
{
	t_node	*nearlylast;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (*stack_a);
	nearlylast = *stack_a;
	while (nearlylast->next->next != NULL)
	{
		nearlylast = nearlylast->next;
	}
	last = nearlylast->next;
	nearlylast->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	return (*stack_a);
}
