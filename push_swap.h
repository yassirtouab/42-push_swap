/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:23:44 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/15 15:37:57 by ytouab           ###   ########.fr       */
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

void		ft_init(t_stack *st, t_check *check);
size_t		ft_strlen(const char *str);
size_t		ft_delimiter(char c);
size_t		ft_wordcount(char *str, t_check *check);
char		**ft_split(char *str, t_check *check);
int			ft_isdigit(int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isdigit_signs(const char *s, t_check *check, t_stack *st);
char		*ft_strdup(const char *str);
int			super_atoi(const char *str, t_check *check, t_stack *st);
void		ft_putstr(char *str);
void		dup_checker(t_stack *st, t_check *check);
int			ft_isvalid_number(char *s, t_check *check, t_stack *st);
void		check_init(t_check *check);
void		stack_init(t_stack *st, t_check *check);
void		ft_validator(char *argument, t_check *check, t_stack *st);
void		ft_joiner(int ac, char **av, t_check *check);
void		ft_error(t_check *check, t_stack *st);
void		ft_parser(t_stack *st, t_check *check);
void		ft_quit(t_check *check, t_stack *st);

// operation functions

void		ft_swap(int *a, int *b);
void		ft_sa(t_stack *st, int pr);
void		ft_sb(t_stack *st, int pr);
void		ft_ss(t_stack *st);
void		ft_pa(t_stack *st);
void		ft_pb(t_stack *st);
void		ft_ra(t_stack *st, int pr);
void		ft_rb(t_stack *st, int pr);
void		ft_rr(t_stack *st);
void		ft_rra(t_stack *st, int pr);
void		ft_rrb(t_stack *st, int pr);
void		ft_rrr(t_stack *st);

int			ft_is_sorted(t_stack *st);
void		ft_sort_small(t_stack *st);
void		ft_sort_five(t_stack *st);
#endif
