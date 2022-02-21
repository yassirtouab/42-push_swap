/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:40:24 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/19 19:40:24 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorted_init(t_stack *st, t_sort *sr, int n)
{
	size_t	i;

	i = 0;
	sr->s = (int *)malloc(st->size_a * sizeof(int));
	while (i < st->size_a)
	{
		sr->s[i] = st->a[i];
		i++;
	}
	ft_sort_s(st, sr);
	sr->sn = sr->s[(st->size_a / n) - 1];
	free(sr->s);
}

void	ft_sort_s(t_stack *st, t_sort *sr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < st->size_a)
	{
		j = 0;
		while (j < st->size_a)
		{
			if (sr->s[i] < sr->s[j])
				ft_swap(&sr->s[i], &sr->s[j]);
			j++;
		}
		i++;
	}
}

int	ft_closest_chunk(t_stack *st, t_sort *sr)
{
	size_t	i;
	int		closest;

	i = st->size_a;
	while (i)
	{
		--i;
		if (st->a[i] <= sr->sn)
			break ;
	}
	closest = st->a[i];
	return (closest);
}

int	ft_in_chunk(t_stack *st, t_sort *sr)
{
	size_t	i;

	i = 0;
	while (i < st->size_a)
	{
		if (st->a[i] <= sr->sn)
			return (1);
		i++;
	}
	return (0);
}

void	ft_pushback_b(t_stack *st)
{
	while (st->size_b)
	{
		if (st->b[st->size_b - 1] == ft_find_biggest(st))
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
		if (st->b[i] > biggest)
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

	index = ft_get_index_b(st, num);
	middle = st->size_b / 2;
	if (middle < index)
		ft_rb(st, 1);
	else
		ft_rrb(st, 1);
}
