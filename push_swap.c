/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/03 23:38:59 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_init(t_stack *st, int ac)
{

	st->valid = 1;
	st->size_a = ac - 1;
	st->size_b = 0;
	st->a = (int *)malloc((st->size_a) * sizeof(int));
	st->b = (int *)malloc((st->size_a) * sizeof(int));
}

void	dup_checker(t_stack *st)
{
	size_t i;
	size_t x;

	i = 0;
	x = 1;
	while (i < st->size_a)
	{
		x = 1;
		while ( i + x < st->size_a)
		{
			if (st->a[i] == st->a[i + x])
			{
				st->valid = 0;
				return ;
			}
			x++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*st;
	st = malloc(sizeof(t_stack));
	stack_init(st, ac);


	int	i;

	i = 0;
	if (ac > 1)
	{
		while (i < st->size_a)
		{
			st->a[i] = super_atoi(av[st->size_a - i], st);
			i++;
		}
	}
	dup_checker(st);
	if (!st->valid)
	{
		ft_putstr("Invalid input, duplicate numbers!\n");
		return (0);
	}
	i = 0;
	while (i < st->size_a)
		printf("%d\n", st->a[i++]);

	return (0);
}
