/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/07 22:14:50 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *st, t_check *check)
{
	if (!check->error)
	{
		st->size_a = check->size;
		st->size_b = 0;
		st->a = (int *)malloc((check->size) * sizeof(int));
		st->b = (int *)malloc((check->size) * sizeof(int));
	}
}

void	check_init(t_check *check)
{
	check->joined = ft_strdup("");
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
	if (ac > 1)
	{
		i = 0;
		while (i++ < ac - 1)
			ft_validator(av[i], check, st);
		ft_joiner(ac, av, st, check);
		ft_parser(st, check);
	}
	i = st->size_a;
	printf("TOP:\n\n");
	while (--i >= 0 && !check->error)
		printf("stack: %d\n", st->a[i]);
	ft_pb(st);
	ft_pb(st);
	ft_pb(st);
	printf("\nAfter op TOP:\n\n");
	i = st->size_a;
	while (--i >= 0 && !check->error)
		printf("ope: %d\n", st->a[i]);

	i = st->size_b;
	printf("TOP:\n\n");
	while (--i >= 0 && !check->error)
		printf("stack: %d\n", st->b[i]);
	ft_sb(st, 1);
	printf("\nAfter op TOP:\n\n");
	i = st->size_b;
	while (--i >= 0 && !check->error)
		printf("ope: %d\n", st->b[i]);

	printf("size_a: %zu\n", st->size_a);
	printf("size_b: %zu\n", st->size_b);
	printf("there is error: %d\n", check->error);
	ft_quit(check, st);
	return (0);
}
