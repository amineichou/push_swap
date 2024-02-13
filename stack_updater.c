/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:59:59 by moichou           #+#    #+#             */
/*   Updated: 2024/02/13 15:00:02 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	a_size;
	int	b_size;

	a_size = ft_stack_size(stack_a);
	b_size = ft_stack_size(stack_b);
	while (stack_b)
	{
		if (stack_b->index <= b_size / 2)
		{
			if (stack_b->target_node->index <= a_size / 2)
				stack_b->coast = stack_b->index + stack_b->target_node->index;
			else
				stack_b->coast = stack_b->index + (a_size - stack_b->target_node->index);
		}
		else if (stack_b->index > b_size / 2)
		{
			if (stack_b->target_node->index > a_size / 2)
				stack_b->coast = (b_size - stack_b->index) + (a_size - stack_b->target_node->index);
			else
				stack_b->coast = (b_size - stack_b->index) + stack_b->target_node->index;
		}
		stack_b = stack_b->next;
	}
}

void	set_index(t_stack_node *stack)
{
	t_stack_node	*head;
	int 			i;

	head = stack;
	i = 0;
	while (head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}

void	set_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*head_a;
	long			magic_number;

	while (stack_b)
	{
		magic_number = LONG_MAX;
		head_a = stack_a;
		while (head_a)
		{
			if (stack_b->value < head_a->value && magic_number > head_a->value)
			{
				magic_number = head_a->value;
				stack_b->target_node = head_a;
			}
			head_a = head_a->next;
		}
		if (magic_number == LONG_MAX)
			stack_b->target_node = ft_get_smallest_value(stack_a);
		stack_b = stack_b->next;
	}
}