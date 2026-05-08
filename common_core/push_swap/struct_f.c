/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:27:28 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/09 13:40:10 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

void	push(struct s_stack *stack, int content)
{
	struct s_node	*new = malloc(sizeof(struct s_node));

	new->value = content;
	new->next = stack->top;
	stack->top = new;
}

int	pop(struct s_stack *stack)
{
	int				pop;
	struct s_node	*tmp;
	
	if (isEmpty(stack) == 1)
		return (-1);
	pop = stack->top->value;
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return (pop);
}
struct s_stack *init(void)
{
	struct s_stack	*new = malloc(sizeof(struct s_stack));

	new->top = NULL;
	return (new);
}
