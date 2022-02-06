/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:43:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/06 22:45:48 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	super_atoi(const char *str, t_check *check, t_stack *st)
{
	int		i;
	int		sym;
	size_t	nb;

	i = 0;
	sym = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sym = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((sym == -1 && nb > 2147483648) || (sym == 1 && nb > 2147483647))
			check->error = 1;
		printf("reached here\n");
		nb = nb * 10 + str[i++] - 48;
	}
	return (nb * sym);
}

void	ft_joiner(int ac, char **av, t_stack *st, t_check *check)
{
	int	i;

	i = 0;
	while (i++ < ac - 1)
	{
		check->joined = ft_strjoin(check->joined, av[i]);
		check->joined = ft_strjoin(check->joined, " ");
	}
}

void	ft_parser(t_stack *st, t_check *check)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!check->error)
	{
		check->splited = ft_split(check->joined);
		while (check->splited[i] && !check->error)
		{
			if (check->error)
				super_atoi(check->splited[i], check, st);
			else
				ft_error(check, st);
			i++;
		}
		if (check->error)
		{
			printf("we fixed it\n");
			ft_error(check, st);
		}
		check->size = i;
		stack_init(st, check);
		while (i--)
			st->a[x++] = super_atoi(check->splited[i], check, st);
		dup_checker(st, check);
	}
}
