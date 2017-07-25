/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 19:09:24 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

void	poperate(char *cmd, t_list **astk, t_list **bstk)
{
	operate(cmd, astk, bstk);
	ft_putendl(cmd);
}

int		is_sort(t_list *lst)
{
	int	*i;
	int	*next;

	while (lst)
	{
		i = lst->content;
		if (lst->next)
			next = lst->next->content;
		if (*i > *next)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		peek(t_list *stk)
{
	int	*i;

	i = stk->content;
	return (*i);
}

int		find_smallest(t_list *stk)
{
	int		i;
	int		hold;
	i = peek(stk);
	while (stk)
	{
		hold = peek(stk);
		if (hold < i)
			i = hold;
		stk = stk->next;
	}
	return (i);
}

int		position(int i, t_list *stk)
{
	int	ret;

	ret = 0;
	while (stk)
	{
		if (peek(stk) == i)
			return (ret);
		stk = stk->next;
		ret++;
	}
	return (ret);
}

void	sort(t_list *astk)
{
	t_list	*bstk;
	int		small;
	int		hold;

	bstk = 0;
	while (is_sort(astk) == 0)
	{
		hold = peek(astk);
		small = find_smallest(astk);
		if (hold == small)
			poperate("pb", &astk, &bstk);
		else if (peek(astk) > peek(astk->next))
			poperate("sa", &astk, &bstk);
		else if (position(small, astk) <= ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
		else if (position(small, astk) > ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
	}
	while (ft_lstlen(bstk))
		poperate("pa", &astk, &bstk);
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	if (is_sort(lst))
		return (0);
	//do the sorting
	sort(lst);
}
