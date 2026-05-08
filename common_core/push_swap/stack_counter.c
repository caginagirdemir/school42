/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:42:52 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/09 20:07:13 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_counter(struct s_stack *stack)
{
	struct  s_node *temp_stack;
	int		count;

	count = 0;
	temp_stack = stack->top;
	while(temp_stack)
	{
		temp_stack = temp_stack->next;
		count++;
	}
	free(temp_stack);
	return (count);
}
