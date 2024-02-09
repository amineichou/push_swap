/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:18:57 by moichou           #+#    #+#             */
/*   Updated: 2024/02/09 18:26:36 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doublcates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// check also for string that only has spaces == empty
static void	check_for_empty_string(char **str, int ac)
{
	int	i;

	i = 1;
	int j;
	if (!*str)
		ft_puterror();
	while (i < ac)
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isspace(str[i][j]))
				break;
			j++;
		}
		if (str[i][j] == '\0')
			ft_puterror();
		i++;
	}
}

static void	check_valid_args(char **av)
{
	int	i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') && av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
				ft_puterror();
			if ((av[i][j] == '+' || av[i][j] == '-') && !av[i][j + 1] )
				ft_puterror();
			if (ft_isdigit(av[i][j]) && av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
				ft_puterror();
			j++;
		}
		i++;
	}
}

// test 
void print_list(t_stack_node *lst)
{
    t_stack_node *test = lst;
    while (test)
    {
        printf("%d ", test->value);
        test = test->next;
    }
}

int main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		check_for_empty_string(av, ac);
		av = ft_split(ft_strjoin(av, ac), ' ');
		check_valid_args(av);
	}
	if (check_doublcates(av))
		ft_puterror();
	stack_a = set_stack(av);
	stack_b = NULL;
	if (!check_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
    print_list(stack_a);
	// if (check_sorted(stack_a))
	// {
	// 	ft_putstr("OK\n");1
	// 	// return (0);
	// }
    return (0);
}
