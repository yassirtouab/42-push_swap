/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:08:04 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 14:08:04 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack *st, int pr)
{
	size_t	i;
	int		*swp;

	if (st->size_a > 1)
	{
		swp = (int *)malloc(st->size_a * sizeof(int));
		i = 0;
		while (i < st->size_a)
		{
			swp[i] = st->a[i];
			i++;
		}
		i = 0;
		st->a[0] = swp[st->size_a - 1];
		while (i++ < st->size_a)
			st->a[i] = swp[i - 1];
		free(swp);
		if (pr)
			ft_putstr("ra\n");
	}
}
