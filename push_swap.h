/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:23:44 by ytouab            #+#    #+#             */
/*   Updated: 2022/02/03 23:31:54 by ytouab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct s_stack {
	int valid;
	int	size_a;
	int	size_b;
	int *a;
	int *b;
}	t_stack;

int	super_atoi(const char *str, t_stack *st);
void	ft_putstr(char *str);
void	dup_checker(t_stack *st);

#endif
