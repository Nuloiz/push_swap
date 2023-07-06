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

t_node	*rotate_last(t_node **stack_a)
{
	t_node	*nearlylast;
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
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
