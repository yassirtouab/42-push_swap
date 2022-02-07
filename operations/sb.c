/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:51:02 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 13:51:02 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack *st, int pr)
{
	if  (st->size_b > 1)
	{
		ft_swap(&(st->b[st->size_b - 1]), &(st->b[st->size_b - 2]));
		if (pr)
			ft_putstr("sb\n");
	}
}
