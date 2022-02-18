/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:17:07 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/18 11:41:23 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init(t_stack *st, t_check *check)
{
	st->size_a = 0;
	st->size_b = 0;
	st->a = NULL;
	st->b = NULL;
	check->joined = NULL;
	check->error = 0;
	check->size = 0;
	check->splited = NULL;
}

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

void	ft_error(t_check *check, t_stack *st)
{
	check->error = 1;
	ft_putstr_fd("Error\n", 2);
	ft_quit(check, st);
}

void	ft_quit(t_check *check, t_stack *st)
{
	free(check->joined);
	while (check->size > 0)
		free(check->splited[--check->size]);
	free(check->splited);
	free(st->a);
	free(st->b);
	free(st);
	free(check);
	exit(0);
}
