/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:09:21 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 14:09:21 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_stack *st)
{
	ft_rra(st, 0);
	ft_rrb(st, 0);
	ft_putstr_fd("rrr\n", 1);
}
