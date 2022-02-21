/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/21 10:32:25 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_three_two(t_stack *st)
{
	if (st->size_a == 2)
		ft_sa(st, 1);
	while (st->size_a == 3 && !ft_is_sorted(st))
	{
		if (((st->a[2] > st->a[1]) && (st->a[0] > st->a[2]))
			|| ((st->a[2] > st->a[1]) && (st->a[1] > st->a[0]))
			|| ((st->a[2] < st->a[0]) && (st->a[1] > st->a[0])))
			ft_sa(st, 1);
		else
			ft_best_move(st, ft_find_smallest(st));
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
		while (!ft_is_sorted(st))
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

void	ft_sort_big(t_stack *st)
{
	t_sort	*sr;
	int		n;

	n = 4;
	sr = malloc(sizeof(t_sort));
	if (st->size_a > 10)
	{
		if (st->size_a > 100)
			n = 11;
		while (n)
		{
			ft_sorted_init(st, sr, n);
			while (st->size_a)
			{
				if (st->a[st->size_a - 1] <= sr->sn)
					ft_pb(st);
				else
					ft_best_move(st, ft_closest_chunk(st, sr));
				if (!ft_in_chunk(st, sr))
					break ;
			}
			n--;
		}
		ft_pushback_b(st);
	}
	free(sr);
}
