/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/19 18:40:42 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_sort_ten(t_stack *st)
{
	if (st->size_a <= 10)
	{
		while (!ft_is_sorted(st) || st->size_a != 5)
		{
			if (ft_find_smallest(st) == st->a[st->size_a - 1])
				ft_pb(st);
			else
				ft_best_move(st, ft_find_smallest(st));
			if (ft_is_sorted(st))
				break ;
		}
		while (st->size_b)
			ft_pa(st);
	}
}
