/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:37:42 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/19 18:37:42 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

int	ft_is_sorted(t_stack *st)
{
	int		sorted;
	size_t	i;

	sorted = 1;
	i = st->size_a;
	if (st->size_a > 1)
	{
		while (--i && sorted)
		{
			if (st->a[i] > st->a[i - 1])
			{
				sorted = 0;
				break ;
			}
		}
		if (sorted)
			return (1);
	}
	return (0);
}

int	ft_find_smallest(t_stack *st)
{
	int		smallest;
	size_t	i;

	i = 0;
	smallest = st->a[st->size_a - 1];
	while (i < st->size_a)
	{
		if (st->a[i] < smallest)
			smallest = st->a[i];
		i++;
	}
	return (smallest);
}

size_t	ft_get_index(t_stack *st, int num)
{
	size_t	index;

	index = 0;
	while (index < st->size_a)
	{
		if (st->a[index] == num)
			return (index);
		index++;
	}
	return (index);
}

void	ft_best_move(t_stack *st, int num)
{
	size_t	index;
	size_t	middle;

	index = ft_get_index(st, num);
	middle = st->size_a / 2;
	if (middle < index)
		ft_ra(st, 1);
	else
		ft_rra(st, 1);
}
