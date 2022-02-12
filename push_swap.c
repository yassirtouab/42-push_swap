/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/12 16:15:13 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*st;
	t_check	*check;
	int		i;

	check = malloc(sizeof(t_check));
	st = malloc(sizeof(t_stack));
	ft_init(st, check);
	check_init(check);
	if (ac > 1)
	{
		i = 0;
		while (i++ < ac - 1)
			ft_validator(av[i], check, st);
		ft_joiner(ac, av, st, check);
		ft_parser(st, check);
	}
	ft_is_sorted(st, check);
	ft_sort_small(st, check);
	i = st->size_a;
	while (--i >= 0)
		printf("stack: %d\n", st->a[i]);
	ft_quit(check, st);
	return (0);
}
