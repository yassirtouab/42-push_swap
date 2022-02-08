/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:19:00 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/08 07:16:51 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit_signs(const char *s, t_check *check, t_stack *st)
{
	size_t	i;

	i = 0;
	if (!s || !ft_strlen(s))
		return (ft_error(check, st));
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9')
			&& !(s[i] == '-' || s[i] == '+' || s[i] == ' '))
			return (ft_error(check, st));
		i++;
	}
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (ft_error(check, st));
	return (1);
}

int	ft_error(t_check *check, t_stack *st)
{
	check->error = 1;
	ft_putstr("Error\n");
	ft_quit(check, st);
	return (0);
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

void	ft_validator(char *argument, t_check *check, t_stack *st)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit_signs(argument, check, st))
		ft_error(check, st);
	while (argument[i])
	{
		while (argument[i] && argument[i] == ' ')
			i++;
		if (argument[i] && (argument[i] == '-' || argument[i] == '+'))
		{
			i++;
			if (!ft_isdigit(argument[i]))
				ft_error(check, st);
			while (argument[i] && ft_isdigit(argument[i]))
				i++;
		}
		while (argument[i] && ft_isdigit(argument[i]))
			i++;
		if (argument[i] && (argument[i] == '-' || argument[i] == '+'))
			ft_error(check, st);
	}
}

int	ft_isvalid_number(char *s, t_check *check, t_stack *st)
{
	size_t	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (!s[1])
			ft_error(check, st);
		else
			i++;
	}
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			ft_error(check, st);
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
				ft_error(check, st);
			x++;
		}
		i++;
	}
}
