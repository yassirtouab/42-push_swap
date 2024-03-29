/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:53:12 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/18 11:43:15 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
		write(fd, &s[i++], 1);
}

size_t	ft_delimiter(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

size_t	ft_wordcount(char *str, t_check *check)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_delimiter(str[i]))
			i++;
		if (str[i] && !ft_delimiter(str[i]))
			nb++;
		while (str[i] && !ft_delimiter(str[i]))
			i++;
	}
	check->size = nb;
	return (nb);
}

char	**ft_split(char *str, t_check *check)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str, check);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (i < wordc)
	{
		while (*str && ft_delimiter(*str))
			str++;
		x = 0;
		while (str[x] && !ft_delimiter(str[x]))
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && !ft_delimiter(*str))
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = 0;
	return (ret);
}
