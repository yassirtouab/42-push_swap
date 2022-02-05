/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:00 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/05 18:31:52 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isvalid_number(char *s, t_check *check)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (!s[1])
		{
			check->error = 1;
			return (0);
		}
		else
			i++;
	}

	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			check->error = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

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


