/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:43:33 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/06 05:33:36 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	super_atoi(const char *str, t_check *check)
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
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	if ((sym == -1 && nb > 2147483648) || (sym == 1 && nb > 2147483647))
	{
		check->error = 0;
		return (0);
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


// void	ft_parser(t_stack *st, t_check *check)
// {
// 	if (!check->error)
// 	{

// 	}
// }
