/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:00 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/06 08:22:26 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit_signs(const char *s, t_check *check)
{
	size_t	i;

	i = 0;
	if (!s || !ft_strlen(s))
		return (ft_error(check));
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9')
			&& !(s[i] == '-' || s[i] == '+' || s[i] == ' '))
			return (ft_error(check));
		i++;
	}
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (ft_error(check));
	return (1);
}

int	ft_error(t_check *check)
{
	check->error = 1;
	return (0);
}

int	ft_checker(char *argument, t_check *check)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit_signs(argument, check))
		return (0);
	while (argument[i])
	{
		while (argument[i] && argument[i] == ' ')
			i++;
		if (argument[i] && (argument[i] == '-' || argument[i] == '+'))
		{
			if (!ft_isdigit(argument[++i]))
				return (ft_error(check));
			while (argument[i] && ft_isdigit(argument[i]))
				i++;
		}
		else
		{
			while (argument[i] && ft_isdigit(argument[i]))
				i++;
			if (argument[i] && (argument[i] == '-' || argument[i] == '+'))
				return (ft_error(check));
		}
	}
	return (1);
}

int	ft_isvalid_number(char *s, t_check *check)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (!s[1])
		{
			check->error = 1;
			return (0);
		}
		else
			i++;
	}
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			check->error = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

void	dup_checker(t_stack *st, t_check *check)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 1;
	while (i < st->size_a)
	{
		x = 1;
		while (i + x < st->size_a)
		{
			if (st->a[i] == st->a[i + x])
				ft_error(check);
			x++;
		}
		i++;
	}
}
