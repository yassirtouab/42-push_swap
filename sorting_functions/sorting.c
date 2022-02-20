/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:00:11 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/20 16:53:31 by ytouab           ###   ########.fr       */
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
	// size_t i;
	int	n = 4;

	sr = malloc(sizeof(t_sort));
	if (st->size_a > 10)
	{
		if (st->size_a > 100)
			n = 8;
		while (n)
		{
			ft_sorted_init(st, sr, n);
			// i = st->size_a - 1;
			// while (i)
			// 	printf("stack s: %d\n", sr->s[--i]);
			// printf("KEY NUMBER: %d\n", sr->sn);
			while (st->size_a)
			{
				if (st->a[st->size_a - 1] <= sr->sn)
					ft_pb(st);
				else
					ft_best_move(st, ft_closest_chunk(st, sr));
				if (!ft_in_chunk(st, sr))
					break ;
			}
			free(sr->s);
			n--;
		}
		ft_pushback_b(st);
	}
	free(sr);
}

int	ft_closest_chunk(t_stack *st, t_sort *sr)
{
	size_t	i;
	// size_t	j;
	int		closest;

	i = st->size_a;
	// j = 0;
	while (i)
	{
		--i;
		if (st->a[i] <= sr->sn)
			break ;
	}
	// while (j < st->size_a)
	// {
	// 	if (st->a[j] < sr->sn)
	// 		break ;
	// 	j++;
	// }
	closest = st->a[i];
	printf("Closest in chunck: %d\n", closest);
	return (closest);
}

int	ft_in_chunk(t_stack *st, t_sort *sr)
{
	size_t	i;

	i = 0;
	while (i < st->size_a)
	{
		if  (st->a[i] <= sr->sn)
			return (1);
		i++;
	}
	return (0);
}

void	ft_pushback_b(t_stack *st)
{
	while (st->size_b)
	{
		if (st->b[st->size_b -1] == ft_find_biggest(st))
			ft_pa(st);
		else
			ft_best_move_b(st, ft_find_biggest(st));
	}
}

int	ft_find_biggest(t_stack *st)
{
	int		biggest;
	size_t	i;

	i = st->size_b;
	biggest = st->b[st->size_b - 1];
	while (i)
	{
		--i;
		if (st->b[i] < biggest)
			biggest = st->b[i];
	}
	return (biggest);
}

size_t	ft_get_index_b(t_stack *st, int num)
{
	size_t	index;

	index = 0;
	while (index < st->size_b)
	{
		if (st->b[index] == num)
			return (index);
		index++;
	}
	return (index);
}

void	ft_best_move_b(t_stack *st, int num)
{
	size_t	index;
	size_t	middle;

	index = ft_get_index(st, num);
	middle = st->size_b / 2;
	if (middle < index)
		ft_rb(st, 1);
	else
		ft_rrb(st, 1);
}
