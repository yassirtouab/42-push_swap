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
	sr->sn = sr->s[st->size_a / n];
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
