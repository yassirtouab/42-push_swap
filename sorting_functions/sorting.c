/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/19 15:44:00 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_three_two(t_stack *st)
{
	if (st->size_a == 2)
		ft_sa(st, 1);
	if (st->size_a == 3)
	{
		if (((st->a[2] > st->a[1]) && (st->a[0] > st->a[2]))
			|| ((st->a[2] > st->a[1]) && (st->a[1] > st->a[0]))
			|| ((st->a[2] < st->a[0]) && (st->a[1] > st->a[0])))
			ft_sa(st, 1);
		if ((st->a[2] < st->a[1]) && (st->a[0] < st->a[2]))
			ft_rra(st, 1);
		if ((st->a[2] > st->a[0]) && (st->a[1] < st->a[0]))
			ft_ra(st, 1);
	}
}

void	ft_sort_four(t_stack *st)
{
	if (st->size_a == 4)
	{
		while (!ft_is_sorted(st) && st->size_a == 4)
		{
			if (ft_find_smallest(st) == st->a[3] && st->size_a == 4)
				ft_pb(st);
			else
				ft_best_move(st, ft_find_smallest(st));
			if (st->size_a == 3)
			{
				ft_three_two(st);
				ft_pa(st);
			}
			if (ft_is_sorted(st) && st->size_a == 4)
				break ;
		}
	}
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

void	ft_sort_five(t_stack *st)
{
	if (st->size_a == 5)
	{
		while (!ft_is_sorted(st) && st->size_a == 5)
		{
			if (ft_find_smallest(st) == st->a[4] && st->size_a == 5)
				ft_pb(st);
			else
				ft_best_move(st, ft_find_smallest(st));
			if (st->size_a == 4)
			{
				ft_sort_four(st);
				ft_pa(st);
			}
			if (ft_is_sorted(st) && st->size_a == 5)
				break ;
		}
	}
}
