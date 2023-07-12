/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:35:42 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/03 11:35:42 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./tools/libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

void	print_list(t_node *p);
void	testing_operations(t_node *stack_a);
int		main(int argc, char	**argv);
t_node	*linked_list_start(int argc, char **argv);
t_node	*sa(t_node *stack_a);
t_node	*sb(t_node *stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	rotate_stack(t_node **stack_a, t_node **stack_b, char *operation);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node *stack_a);
int		already_sorted(int argc, char **argv);
char	**new_numbers(int argc, char **argv);

#endif