/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/06 05:35:26 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *st, t_check *check)
{
	st->size_a = check->size;
	st->size_b = check->size;
	st->a = (int *)malloc((st->size_a) * sizeof(int));
	st->b = (int *)malloc((st->size_a) * sizeof(int));
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
	stack_init(st, check);
	if (ac > 1)
	{
		i = 0;
		while (i++ < ac - 1)
			printf("Check |%s| |%d|\n", av[i], ft_checker(av[i], check));
	}

	ft_joiner(ac, av, st, check);
	printf("Joined: |%s|\n", check->joined);
	printf("There is %d error\n", check->error);
	return (0);
}
