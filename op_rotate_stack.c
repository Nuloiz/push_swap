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

static t_node	*ra_rb(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (*stack);
	first = *stack;
	second = first->next;
	last = first->next;
	while (last->next != NULL)
	{
		last = last->next;
	}
	first->next = last->next;
	last->next = first;
	*stack = second;
	return (*stack);
}

static t_node	*rra_rrb(t_node **stack)
{
	t_node	*new_first;
	t_node	*new_second;
	t_node	*new_last;

	new_second = *stack;
	new_first = ft_lstlast(new_second);
	new_last = *stack;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	new_last->next = NULL;
	ft_lstadd_front(stack, new_first);
	return (0);
}

static void	rr_to_rrr(t_node **stack_a, t_node **stack_b, char *operation)
{
	if (operation[2] == 'a')
	{
		*stack_a = rra_rrb(stack_a);
		ft_printf("rra\n");
	}
	else if (operation[2] == 'b')
	{
		*stack_b = rra_rrb(stack_b);
		ft_printf("rrb\n");
	}
	else if (operation[2] == 'r')
	{
		*stack_a = rra_rrb(stack_a);
		*stack_b = rra_rrb(stack_b);
		ft_printf("rrr\n");
	}
	else
	{
		*stack_a = ra_rb(stack_a);
		*stack_b = ra_rb(stack_b);
		ft_printf("rr\n");
	}
}

void	rotate_stack(t_node **stack_a, t_node	**stack_b, char	*operation)
{
	if (operation[1] == 'a')
	{
		*stack_a = ra_rb(stack_a);
		ft_printf("ra\n");
	}
	else if (operation[1] == 'b')
	{
		*stack_b = ra_rb(stack_b);
		ft_printf("rb\n");
	}
	else if (operation[1] == 'r')
		rr_to_rrr(stack_a, stack_b, operation);
}
