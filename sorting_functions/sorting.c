/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/16 07:20:31 by ytouab           ###   ########.fr       */
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
	while (++i < st->size_a)
	{
		if (st->a[i] < smallest)
			smallest = st->a[i];
	}
	return (smallest);
}

void	ft_sort_small(t_stack *st)
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

void	ft_sort_five(t_stack *st)
{
	while (!ft_is_sorted(st) && st->size_a != 5)
	{
		if (st->size_a == 3)
		{
			ft_sort_small(st);
			ft_pa(st);
			ft_pa(st);
		}
		if (ft_find_smallest(st) == st->a[st->size_a - 1])
			ft_pb(st);
		else
			ft_ra(st, 1);
	}
}
