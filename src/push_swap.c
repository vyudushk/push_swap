/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/08/13 19:49:18 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

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
		else if (position(small, astk) > ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (hold == big && ft_lstlen(astk) > 1)
			poperate("ra", &astk, &bstk);
		else if ((peek(astk) > peek(astk->next)))
			poperate("sa", &astk, &bstk);
		else if (position(small, astk) <= ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
	}
	while (ft_lstlen(bstk))
		poperate("pa", &astk, &bstk);
}

/*int		check_gap(t_list *stk)
{
	int	len;
	//int	sum;

	len = ft_lstlen(stk);
}
*/
void	sort_big(t_list *astk)
{
	t_list	*bstk;

	bstk = 0;
	while (is_sort_push(astk) == 0)
	{
		if (ft_lstlen(bstk) < 2)
			poperate("pb", &astk, &bstk);
		else if ((peek(astk) > peek(astk->next)) && (peek(bstk) < peek(bstk->next)))
			poperate("ss", &astk, &bstk);
		else if ((peek(astk) > peek(astk->next)))
			poperate("sa", &astk, &bstk);
		else if ((peek(bstk) < peek(bstk->next)))
			poperate("sb", &astk, &bstk);
		else if (peek(astk) < peek(bstk))
			poperate("pb", &astk, &bstk);
		else if (peek(astk) > peek(bstk))
			poperate("ra", &astk, &bstk);
		if (ft_lstlen(astk) == 10)
			exit(0);
	}
	while (ft_lstlen(bstk))
	{
		poperate("pa", &astk, &bstk);
		if (peek(astk) > peek(astk->next))
			poperate("ra", &astk, &bstk);
	}
}

/*
**	if (ft_lstlen(astk) < 50)
**		sort_big(astk);
**	else
**		sort_big(astk);
*/

void	pick_sort(t_list *astk)
{
	sort_big(astk);
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	if (is_sort_push(lst))
		return (0);
	pick_sort(lst);
}
