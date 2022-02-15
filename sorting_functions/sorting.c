/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/15 19:45:43 by ytouab           ###   ########.fr       */
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
	if (!ft_is_sorted(st) && st->size_a < 6)
	{
		if (st->size_a == 5)
			ft_pb(st);
		if (st->size_a == 4)
			ft_pb(st);
		if (st->size_a == 3)
		{
			ft_sort_small(st);
			ft_pa(st);
		}
		if (!ft_is_sorted(st))
			ft_ra(st, 1);
		ft_pa(st);
		if (!ft_is_sorted(st))
			ft_rra(st, 1);
	}
}
