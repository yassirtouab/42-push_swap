/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:23:44 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/04 22:06:55 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	size_t	size_a;
	size_t	size_b;
	int		*a;
	int		*b;
}				t_stack;

typedef struct s_check {
	int		error;
	char	*checker;
	size_t	size;
}				t_check;

size_t		ft_strlen(const char *str);
size_t		ft_delimiter(char c, char *charset);
size_t		ft_wordcount(char *str, char *charset);
char		**ft_split(char *str, char *charset);
char		*ft_strjoin_check(char const *s1, char const *s2, t_check *check);
int			ft_isdigit_signs(const char *s);
char		*ft_strdup(const char *str);
int			super_atoi(const char *str, t_check *check);
void		ft_putstr(char *str);
void		dup_checker(t_stack *st, t_check *check);
void		check_init(t_check *check);
void		stack_init(t_stack *st, t_check *check);

#endif
