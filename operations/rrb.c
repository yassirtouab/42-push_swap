/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:09:17 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 14:09:17 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrb(t_stack *st, int pr)
{
	size_t	i;
	int		*swp;

	if (st->size_b > 1)
	{
		swp = (int *)malloc(st->size_b * sizeof(int));
		i = 0;
		while (i < st->size_b)
		{
			swp[i] = st->b[i];
			i++;
		}
		i = 0;
		 st->b[st->size_b - 1] = swp[0];
		while (i < st->size_b - 1)
		{
			st->b[i] = swp[i + 1];
			i++;
		}
		free(swp);
		if (pr)
			ft_putstr("rrb\n");
	}
}
