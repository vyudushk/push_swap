/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 01:33:32 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 15:56:57 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H

# include "libft.h"

void	operate(char *cmd, t_list **astk, t_list **bstk);

int		isnumeric(char *str);
int		isduplicate(t_list *lst, int check);
int		isvalid(char *str);

void	leave(void);
void	print_lst(t_list *lst);
void	debug(t_list *lst, t_list *stack);

t_list	*arg_to_lst(int argc, char **argv);

#endif
