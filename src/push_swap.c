/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/28 17:11:46 by vyudushk         ###   ########.fr       */
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

int		find_biggest(t_list *stk)
{
	int		i;
	int		hold;

	i = peek(stk);
	while (stk)
	{
		hold = peek(stk);
		if (hold > i)
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

void	sort_10(t_list *astk)
{
	t_list	*bstk;
	int		hold;
	int		small;
	int		big;

	bstk = 0;
	while (is_sort(astk) == 0)
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

void	int_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

int		find_fit_end(int big, int small, t_list *stk)
{
	if (small < peek(stk) && peek(stk) < big)
		return (1);
	if (stk->next)
		return (find_fit_end(big, small, stk->next) + 1);
	return (0);
}

int		find_fit(int big, int small, t_list *stk)
{
	int	ret;

	ret = 0;
	while (stk)
	{
		if (small < peek(stk) && peek(stk) < big)
			return (ret);
		stk = stk->next;
		ret++;
	}
	return (ret);
}

void	sort_big(t_list *astk)
{
	t_list	*bstk;
	int		small;
	int		big;

	bstk = 0;
	poperate("pb", &astk, &bstk);
	while (peek(astk) + 1 == peek(bstk) || peek(astk) - 1 == peek(bstk))
		poperate("ra", &astk, &bstk);
	poperate("pb", &astk, &bstk);
	if (peek(bstk) != find_smallest(bstk))
		poperate("rb", &astk, &bstk);
	small = peek(bstk);
	big = peek(bstk->next);
	while (is_sort(astk) == 0)
	{
		if (small < peek(astk) && peek(astk) < big)
			poperate("pb", &astk, &bstk);
		if (find_fit(big, small, astk))
			poperate("ra", &astk, &bstk);
	}
}

void	pick_sort(t_list *astk)
{
	if (ft_lstlen(astk) < 50)
		sort_big(astk);
	else
		sort_big(astk);
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	if (is_sort(lst))
		return (0);
	//do the sorting
	pick_sort(lst);
}
