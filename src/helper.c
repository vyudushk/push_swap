/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 06:08:45 by vyudushk          #+#    #+#             */
/*   Updated: 2017/08/13 19:39:32 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "libpush.h"

void	int_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

void	poperate(char *cmd, t_list **astk, t_list **bstk)
{
	operate(cmd, astk, bstk);
	ft_putendl(cmd);
}

void	leave(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	print_lst(t_list *lst)
{
	int		*i;

	i = lst->content;
	ft_putnbr(*i);
	ft_putchar(' ');
}

void	debug(t_list *lst, t_list *stack)
{
	ft_putnbr(ft_lstlen(lst));
	ft_putstr(" A : ");
	ft_lstiter(lst, print_lst);
	ft_putchar('\n');
	ft_putnbr(ft_lstlen(stack));
	ft_putstr(" B : ");
	ft_lstiter(stack, print_lst);
	ft_putchar('\n');
	ft_putchar('\n');
}
