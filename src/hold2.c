/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:44:11 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 15:58:06 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

void	sort_10(t_list *astk)
{
	t_list	*bstk;
	int		hold;
	int		small;
	int		big;

	bstk = 0;
	while (is_sort_push(astk) == 0)
	{
		hold = peek(astk);
		small = find_smallest(astk);
		big = find_biggest(astk);
		if (hold == small)
			poperate("pb", &astk, &bstk);
		else if (hold == big && ft_lstlen(astk) > 1)
			poperate("ra", &astk, &bstk);
		else if ((peek(astk) > peek(astk->next)))
			poperate("sa", &astk, &bstk);
		else if (position(small, astk) > ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (position(small, astk) <= ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
	}
	while (ft_lstlen(bstk))
		poperate("pa", &astk, &bstk);
}

int		any_below(t_list *stk, int i)
{
	while (stk)
	{
		if (peek(stk) <= i)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int		any_above(t_list *stk, int i)
{
	while (stk)
	{
		if (peek(stk) >= i)
			return (1);
		stk = stk->next;
	}
	return (0);
}

t_list	*copy_lst(t_list *lst)
{
	t_list *ret;

	ret = ft_lstnew(0, 0);
	ret->content = lst->content;
	ret->content_size = lst->content_size;
	return (ret);
}

void	pick_sort(t_list *astk)
{
	if (ft_lstlen(astk) < 10)
		sort_10(astk);
	else
		sort_big(astk, 0, find_avg(astk));
}
