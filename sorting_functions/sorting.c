/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/12 18:42:13 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_is_sorted(t_stack *st, t_check *check)
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
			ft_quit(check, st);
	}
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
