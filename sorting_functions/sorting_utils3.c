/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 05:19:39 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/22 05:25:30 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
