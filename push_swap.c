/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/04 20:26:59 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_init(t_stack *st, t_check *check)
{
	st->size_a = check->size;
	st->size_b = check->size;
	st->a = (int *)malloc((st->size_a) * sizeof(int));
	st->b = (int *)malloc((st->size_a) * sizeof(int));
}

void	check_init(t_check *check)
{
	check->checker = ft_strdup("");
	check->error = 0;
	check->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	*st;
	t_check	*check;
	int		i;

	check = malloc(sizeof(t_check));
	st = malloc(sizeof(t_stack));
	check_init(check);
	stack_init(st, check);
	if (ac > 1)
	{
		i = 0;
		while (i++ < ac - 1)
		{
			check->checker = ft_strjoin_check(check->checker, av[i], check);
			check->checker = ft_strjoin_check(check->checker, " ", check);
		}
	}
	i = 0;
	printf("%d\n", check->error);
	// while (i < st->size_a)
		printf("%s\n", check->checker);

	return (0);
}
