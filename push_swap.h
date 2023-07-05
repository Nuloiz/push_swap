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

int	main_s(int argc, char	**argv);
int	linked_list_start(int argc, char **argv);
#endif