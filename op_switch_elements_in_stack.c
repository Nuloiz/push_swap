/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:59 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/06 11:31:59 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sa(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a == NULL || stack_a->next == NULL)
		return (stack_a);
	first = stack_a;
	second = stack_a->next;
	first->next = second->next;
	second->next = first;
	stack_a = second;
	ft_printf("sa\n");
	return (stack_a);
}

t_node	*sb(t_node *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_b == NULL || stack_b->next == NULL)
		return (stack_b);
	first = stack_b;
	second = stack_b->next;
	first->next = second->next;
	second->next = first;
	stack_b = second;
	ft_printf("sb\n");
	return (stack_b);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_printf("ss\n");
	return ;
}
