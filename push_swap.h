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

t_node	*test_stack_b(int argc);
int		main(int argc, char	**argv);
t_node	*linked_list_start(int argc, char **argv);
t_node	*swap_first(t_node *head);
t_node	*rotate_first(t_node **head);
t_node	*rotate_last(t_node **head);
void	push_stack(t_node	**stack_get, t_node **stack_loose);
void	print_list(t_node *p);

#endif