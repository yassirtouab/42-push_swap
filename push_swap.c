/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/22 07:41:32 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter(t_stack *st, t_check *check)
{
	if (ft_is_sorted(st) || st->size_a == 1)
		ft_quit(check, st);
	else if (st->size_a <= 3)
		ft_three_two(st);
	else if (st->size_a == 4)
		ft_sort_four(st);
	else if (st->size_a == 5)
		ft_sort_five(st);
	else if (st->size_a <= 10)
		ft_sort_ten(st);
	else if (st->size_a > 10)
		ft_sort_big(st);
}

int	main(int ac, char **av)
{
	t_stack	*st;
	t_check	*check;
	int		i;

	if (ac > 1)
	{
		check = malloc(sizeof(t_check));
		st = malloc(sizeof(t_stack));
		ft_init(st, check);
		check_init(check);
		i = 0;
		while (i++ < ac - 1)
			ft_validator(av[i], check, st);
		ft_joiner(ac, av, check);
		ft_parser(st, check);
		ft_sorter(st, check);
		ft_quit(check, st);
	}
	return (0);
}
