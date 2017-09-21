/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 01:33:32 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 12:58:16 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H

# include "libft.h"

int		find_biggest(t_list *stk);
int		find_smallest(t_list *stk);
int		peek(t_list *stk);
int		peek_last(t_list *stk);

void	operate(char *cmd, t_list **astk, t_list **bstk);
void	poperate(char *cmd, t_list **astk, t_list **bstk);
void	int_swap(int *a, int *b);

int		is_sort_push(t_list *lst);
int		isnumeric(char *str);
int		isduplicate(t_list *lst, int check);
int		isvalid(char *str);

void	leave(void);
void	print_lst(t_list *lst);
void	debug(t_list *lst, t_list *stack);

t_list	*arg_to_lst(int argc, char **argv);

int		allsmaller(t_list *stk, int b);
int		find_avg(t_list *stk);
int		allbigger(t_list *stk, int b);
int		position_avg(int i, t_list *stk, int set);
int		position(int i, t_list *stk);

void	sort_10(t_list *astk);
int		any_below(t_list *stk, int i);
int		any_above(t_list *stk, int i);
t_list	*copy_lst(t_list *lst);
void	pick_sort(t_list *astk);

void	sort_big(t_list *astk, t_list *bstk, int avg);

void	soft_end(t_list *astk, t_list *bstk);
int		soft_end_test(t_list *astk, t_list *bstk);
void	hard_end(t_list *astk, t_list *bstk);
int		hard_end_test(t_list *astk, t_list *bstk);

#endif
