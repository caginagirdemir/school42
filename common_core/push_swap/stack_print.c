/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagirdem <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:59:01 by cagirdem          #+#    #+#             */
/*   Updated: 2022/02/09 20:07:26 by cagirdem         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	*get_stack(struct s_stack *stack)
{
	int *a;
	int i;
	
	i = 0;
	a = (int *)malloc(stack_counter(stack) * sizeof(int));
	while(stack->top)
	{
		a[i] = stack->top->value;
		pop(stack);
		i++;
	}
	a[i] = -1;
	i--;
	while(i >= 0)
	{
		push(stack, a[i]);
		i--;
	}
	return (a);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	print_stack(struct s_stack *stack_a, struct s_stack *stack_b)
{
	int	*arr_a;	
	int	*arr_b;
	int	i_a;
	int	i_b;
	int max;
	int k;

	arr_a = get_stack(stack_a);
	arr_b = get_stack(stack_b);
	i_a = 0;
	i_b = 0;
	max = 0;
	k = 0;
	while (arr_a[i_a] != -1)
		i_a++;
	while (arr_b[i_b] != -1)
		i_b++;
	max = get_max(i_a, i_b);
	while (k < max)
	{
		if (i_a != 0)
		{
			printf("%d ",arr_a[k]);
			i_a--;
		}
		else
			printf("x ");

		if (i_b != 0)
		{
			printf("%d \n", arr_b[k]);
			i_b--;
		}
		else
			printf("x \n");
		k++;
	}
	printf("- -\n");
	printf("a b\n\n");
}
