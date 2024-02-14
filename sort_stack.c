/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:07:44 by moichou           #+#    #+#             */
/*   Updated: 2024/02/14 18:16:33 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack_node **stack)
{
	if (check_sorted(*stack))
		return ;
	if ((*stack)->value > (*stack)->next->value)
		swap_stack_a(stack);
	if (!check_sorted(*stack))
		reverse_rotate_a(stack);
	if (!check_sorted(*stack))
		swap_stack_a(stack);
}

// static void	rotate_target_node(t_stack_node *target_node)
// {
// 	int				index;
// 	int				a_size;

// 	a_size = ft_stack_size(target_node);
// 	index = target_node->index;
// 	printf("asize %d\n", index);
// 	while (index)
// 	{
// 		//printf("should mount\n");
// 		if (target_node->index >= a_size / 2)
// 			rotate_a(&target_node);
// 		else
// 			reverse_rotate_a(&target_node);
// 		index--;
// 	}
// }

// static void	rotate_lowest_coast_n_target(t_stack_node **stack)
// {
// 	t_stack_node	*node_lowest_coast;
// 	t_stack_node	*target_node;
// 	int				lowest_coast;
// 	int				b_size;

// 	node_lowest_coast = ft_get_lowest_coast(*stack);
// 	lowest_coast = node_lowest_coast->coast;
// 	target_node = (*stack)->target_node;
// 	b_size = ft_stack_size(*stack);
// 	while (lowest_coast)
// 	{
// 		if (node_lowest_coast->index >= b_size / 2)
// 			rotate_b(stack);
// 		else
// 			reverse_rotate_b(stack);
// 		lowest_coast--;
// 	}
// 	rotate_target_node(target_node);
// }

static void update_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index(*stack_a);
	set_index(*stack_b);
	set_target_node(*stack_a, *stack_b);
	set_position_middle(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
}

// static void	final_step(t_stack_node **stack)
// {
// 	t_stack_node	*smallest_node_value;
// 	int				s_size;
// 	int				index;

// 	smallest_node_value = ft_get_smallest_value(*stack);
// 	s_size = ft_stack_size(*stack);
// 	index = smallest_node_value->index;
// 	if (index < s_size / 2)
// 	{
// 		while (index--)
// 			rotate_a(stack);
// 	}
// 	else if (index >= s_size / 2)
// 	{
// 		while (index--)
// 			reverse_rotate_a(stack);
// 	}
// }

static void	best_move(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_stack_size(*stack_a);
	while (stack_a_size > 3)
	{
		if (!(*stack_b))
			push_a_to_b(stack_a, stack_b);
		else if ((*stack_a)->value > (*stack_b)->value) // big in bottom
		{
			push_a_to_b(stack_a, stack_b);
			swap_stack_b(stack_b);
		}
		else
			push_a_to_b(stack_a, stack_b);
		stack_a_size--;
	}
	sort_three(stack_a);
	// while (*stack_b)
	// {
		update_stack(stack_a, stack_b);
	//	rotate_lowest_coast_n_target(stack_b);
	// 	push_b_to_a(stack_a, stack_b);
	// }
	//final_step(stack_a);
}

void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size > 3)
		best_move(stack_a, stack_b);
}