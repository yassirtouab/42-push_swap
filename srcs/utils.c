/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:53:12 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/04 19:07:55 by ytouab           ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

size_t	ft_delimiter(char c, char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_wordcount(char *str, char *charset)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_delimiter(str[i], charset))
			i++;
		if (str[i] && !ft_delimiter(str[i], charset))
			nb++;
		while (str[i] && !ft_delimiter(str[i], charset))
			i++;
	}
	return (nb);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	size_t	wordc;
	size_t	i;
	size_t	x;

	wordc = ft_wordcount(str, charset);
	ret = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (i < wordc)
	{
		while (*str && ft_delimiter(*str, charset))
			str++;
		x = 0;
		while (str[x] && !ft_delimiter(str[x], charset))
			x++;
		ret[i] = (char *)malloc(x + 1);
		x = 0;
		while (*str && !ft_delimiter(*str, charset))
			ret[i][x++] = *str++;
		ret[i++][x] = 0;
	}
	ret[i] = 0;
	return (ret);
}
