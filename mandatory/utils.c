/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:39:53 by moichou           #+#    #+#             */
/*   Updated: 2024/02/08 18:59:18 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	stack_size(t_stack_node *stack)
{
	t_stack_node	*last;
	int				i;

	i = 0;
	if (!stack)
		return (0);
	last = stack;
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}

t_stack_node	*get_last_node(t_stack_node **stack)
{
    t_stack_node *last;

    if (!(*stack))
        return (NULL);
    last = *stack;
    while (last->next)
        last = last->next;
    return (last);
}

int	check_sorted(t_stack_node *stack)
{
	t_stack_node	*head;
	int				is_sorted;

	head = stack;
	is_sorted = 1;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			ft_puterror();
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_puterror(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

char	*ft_strjoin(char **str, int ac)
{
	char	*result;
	int		size;
	int		i;
	int		x;

	i = 1;
	size = 0;
	while (i < ac)
		size += ft_strlen(str[i++]);
	result = malloc(sizeof(char) * (size + ac));
	if (!result)
		return (NULL);
	i = 1;
	x = 0;
	while (i < ac)
	{
		size = 0;
		while (str[i][size])
			result[x++] = str[i][size++];
		result[x] = ' ';
		x++;
		i++;
	}
	result[x] = '\0';
	return (result);
}


// test apps

void test_putargs(char **av, int ac)
{
    for (int i = ac - 1; i; i--)
    {
        ft_putstr(av[i]);
        ft_putstr("\n");
    }
}

void test_putsplited(char **av)
{
    int i = 0;
    while (av[i])
    {
        ft_putstr(av[i]);
        ft_putstr("\n");
        i++;
    }
}