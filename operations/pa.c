/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:06:26 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 14:06:26 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack *st)
{
	if (st->size_b > 0)
	{
		st->a[st->size_a++] = st->b[--st->size_b];
		ft_putstr_fd("pa\n", 1);
	}
}
