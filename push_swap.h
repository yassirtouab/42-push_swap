/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:23:44 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/06 22:52:07 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack {
	size_t	size_a;
	size_t	size_b;
	int		*a;
	int		*b;
}				t_stack;

typedef struct s_check {
	int		error;
	char	*joined;
	char	**splited;
	size_t	size;
}				t_check;

size_t		ft_strlen(const char *str);
size_t		ft_delimiter(char c);
size_t		ft_wordcount(char *str);
char		**ft_split(char *str);
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_isdigit_signs(const char *s, t_check *check, t_stack *st);
char		*ft_strdup(const char *str);
int			super_atoi(const char *str, t_check *check, t_stack *st);
void		ft_putstr(char *str);
void		dup_checker(t_stack *st, t_check *check);
int			ft_isvalid_number(char *s, t_check *check, t_stack *st);
void		check_init(t_check *check);
void		stack_init(t_stack *st, t_check *check);
int			ft_validator(char *argument, t_check *check, t_stack *st);
void		ft_joiner(int ac, char **av, t_stack *st, t_check *check);
int			ft_error(t_check *check, t_stack *st);
void		ft_parser(t_stack *st, t_check *check);
void		ft_quit(t_check *check, t_stack *st);

#endif
