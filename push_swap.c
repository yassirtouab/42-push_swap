/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/15 18:32:01 by ytouab           ###   ########.fr       */
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
		ft_joiner(ac, av, check);
		ft_parser(st, check);
	}
	if (ft_is_sorted(st))
		ft_quit(check, st);
	//ft_sort_small(st);
	ft_sort_five(st);

	i = st->size_a;
	while (--i >= 0)
		printf("stack a: %d\n", st->a[i]);
	printf("\n\n");
	i = st->size_b;
	while (--i >= 0)
		printf("stack b: %d\n", st->b[i]);
	printf("size a %zu\n", st->size_a);
	printf("size b %zu\n", st->size_b);
	ft_quit(check, st);
	return (0);
}
