/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:00 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/04 19:41:22 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	dup_checker(t_stack *st, t_check *check)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 1;
	while (i < st->size_a)
	{
		x = 1;
		while (i + x < st->size_a)
		{
			if (st->a[i] == st->a[i + x])
			{
				check->error = 0;
				return ;
			}
			x++;
		}
		i++;
	}
}


