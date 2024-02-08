/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:50:42 by moichou           #+#    #+#             */
/*   Updated: 2024/02/08 18:45:47 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// test
#include <stdio.h>

typedef struct s_stack_node
{
	int 				value;
	int					index;
    int					coast;
	int					is_above_middle;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
} t_stack_node;

// extr funcs
t_stack_node	*set_stack(char **splited);
char			**ft_split(char const *s, char c);

//utils
size_t			ft_strlen(const char *str);
int				stack_size(t_stack_node *stack);
t_stack_node    *get_last_node(t_stack_node **stack);
int				check_sorted(t_stack_node *stack);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strjoin(char **str, int ac);
int				ft_isspace(char c);
void			ft_putstr(char *s);
void			ft_puterror(void);


// swap
void	swap_stack_a(t_stack_node **stack);
void	swap_stack_b(t_stack_node **stack);
void	swap_stack_a_b(t_stack_node **stack_a, t_stack_node **stack_b);

// rotate
void	rotate_a(t_stack_node **stack);
void	rotate_b(t_stack_node **stack);

// reverse rotate
void	reverse_rotate_a(t_stack_node **stack);
void	reverse_rotate_b(t_stack_node **stack);

// push
void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void	push_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);

// sorting algorithm
void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b);


// test apps /utils
void test_putargs(char **av, int ac);
void test_putsplited(char **av);

# endif