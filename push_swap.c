/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:26:58 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/05 18:55:54 by ytouab           ###   ########.fr       */
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
	check->checker = ft_strdup("");
	check->error = 0;
	check->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	*st;
	t_check	*check;
	int		i;
	char 	**parsed;

	check = malloc(sizeof(t_check));
	st = malloc(sizeof(t_stack));
	check_init(check);
	stack_init(st, check);
	if (ac > 1)
	{
		i = 0;
		while (i++ < ac - 1 && ft_isdigit_signs(av[i], check))
		{
			check->checker = ft_strjoin_check(check->checker, av[i], check);
			check->checker = ft_strjoin_check(check->checker, " ", check);
		}
	}
	parsed = ft_split(check->checker);

	i = -1;

	printf("%s\n", check->checker);
	while (parsed[++i])
		printf("%s valid: %d\n", parsed[i], ft_isvalid_number(parsed[i], check));
	printf("There is %d error\n", check->error);

	return (0);
}
