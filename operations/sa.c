/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:50:39 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 13:50:39 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	ft_sa(t_stack *st, int pr)
{
	if (st->size_a > 1)
	{
		ft_swap(&(st->a[st->size_a - 1]), &(st->a[st->size_a - 2]));
		if (pr)
			ft_putstr("sa\n");
	}
}
