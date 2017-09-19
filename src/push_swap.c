/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/18 00:58:32 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

int		position_avg(int i, t_list *stk, int set)
{
	int	ret;

	ret = 0;
	while (stk)
	{
		if (set == 0 && peek(stk) <= i)
			return (ret);
		else if (peek(stk) >= i)
			return (ret);
		stk = stk->next;
		ret++;
	}
	return (ret);
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

int		allbigger(t_list *stk, int b)
{
	while (stk)
	{
		if (peek(stk) < b)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int		allsmaller(t_list *stk, int b)
{
	while (stk)
	{
		if (peek(stk) > b)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int		find_avg(t_list *stk)
{
	int	len;
	int	total;

	len = ft_lstlen(stk);
	total = 0;
	while (stk)
	{
		total += peek(stk);
		stk = stk->next;
	}
	if (len)
		return (total / len);
	else
		return (0);
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

void	soft_end(t_list *astk, t_list *bstk)
{
	while (ft_lstlen(bstk))
		if (peek(bstk) == find_biggest(bstk))
		{
			poperate("pa", &astk, &bstk);
			if (peek(astk) > peek(astk->next))
				poperate("sa", &astk, &bstk);
		}
		else if (position(find_biggest(bstk), bstk) >= ft_lstlen(bstk) / 2)
			poperate("rrb", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) < ft_lstlen(bstk) / 2)
			poperate("rb", &astk, &bstk);
}

int	soft_end_test(t_list *astk, t_list *bstk)
{
	int	ret;

	ret = 0;
	while (ft_lstlen(bstk))
	{
		ret++;
		if (peek(bstk) == find_biggest(bstk))
		{
			operate("pa", &astk, &bstk);
			if (peek(astk) > peek(astk->next))
			{
				operate("sa", &astk, &bstk);
				ret++;
			}
		}
		else if (position(find_biggest(bstk), bstk) >= ft_lstlen(bstk) / 2)
			operate("rrb", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) < ft_lstlen(bstk) / 2)
			operate("rb", &astk, &bstk);
	}
	return (ret);
}

void	hard_end(t_list *astk, t_list *bstk)
{
	while (ft_lstlen(bstk))
	{
		if (peek(bstk) < peek(astk))
			poperate("pa", &astk, &bstk);
		else if (peek(bstk) > peek(astk))
			poperate("ra", &astk, &bstk);
		while (ft_lstlen(bstk) && peek_last(astk) < peek(astk) && peek_last(astk) > peek(bstk))
		{
			if (peek_last(astk) )
			poperate("rra", &astk, &bstk);
		}
	}
	while (peek(astk) != find_smallest(astk))
			poperate("rra", &astk, &bstk);
}

int	hard_end_test(t_list *astk, t_list *bstk)
{
	int	ret;

	ret = 0;
	while (ft_lstlen(bstk))
	{
		if (peek(bstk) < peek(astk))
			operate("pa", &astk, &bstk);
		else if (peek(bstk) > peek(astk))
			operate("ra", &astk, &bstk);
		ret++;
		while (ft_lstlen(bstk) && peek_last(astk) < peek(astk) && peek_last(astk) > peek(bstk))
		{
			if (peek_last(astk))
				operate("rra", &astk, &bstk);
			ret++;
		}
	}
	while (peek(astk) != find_smallest(astk))
	{
			operate("rra", &astk, &bstk);
			ret++;
	}
	return (ret);
}

t_list	*copy_lst(t_list *lst)
{
	t_list *ret;

	ret = ft_lstnew(0, 0);
	ret->content = lst->content;
	ret->content_size = lst->content_size;
	return (ret);
}

void	finish_sort(t_list *astk, t_list *bstk)
{
	t_list	*acpy;
	t_list	*bcpy;
	int		hard;
	int		soft;

	acpy = ft_lstmap(astk, copy_lst);
	bcpy = ft_lstmap(bstk, copy_lst);
	hard = hard_end_test(acpy, bcpy);
	acpy = ft_lstmap(astk, copy_lst);
	bcpy = ft_lstmap(bstk, copy_lst);
	soft = soft_end_test(acpy, bcpy);
	if (hard < soft)
		hard_end(astk, bstk);
	else
		soft_end(astk, bstk);
}

void	sort_big(t_list *astk, t_list *bstk)
{
	int	avg;

	avg = find_avg(astk);
	while (any_below(astk, avg))
	{
		if (peek(astk) <= avg)
			poperate("pb", &astk, &bstk);
		else if (position_avg(avg, astk, 0) >= ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (position_avg(avg, astk, 0) < ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
	}
	avg = find_avg(bstk);
	while (any_above(bstk, avg))
	{
		if (peek(bstk) >= avg)
			poperate("pa", &astk, &bstk);
		else if (position_avg(avg, bstk, 1) >= (ft_lstlen(bstk) / 2))
			poperate("rrb", &astk, &bstk);
		else if (position_avg(avg, bstk, 1) < (ft_lstlen(bstk) / 2))
			poperate("rb", &astk, &bstk);
	}
	avg = find_avg(astk);
	while (any_below(astk, avg))
	{
		if (is_sort_push(astk))
			break;
		if (peek(astk) <= avg)
			poperate("pb", &astk, &bstk);
		else if (position_avg(avg, astk, 0) >= ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (position_avg(avg, astk, 0) < ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
		if (any_below(astk, avg) == 0)
			avg = find_avg(astk);
	}
	while (ft_lstlen(bstk) && ft_lstlen(astk) == 0)
		if (peek(bstk) == find_biggest(bstk))
			poperate("pa", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) >= ft_lstlen(bstk) / 2)
			poperate("rrb", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) < ft_lstlen(bstk) / 2)
			poperate("rb", &astk, &bstk);
	finish_sort(astk, bstk);
}

void	pick_sort(t_list *astk)
{
	sort_big(astk, 0);
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	if (is_sort_push(lst))
		return (0);
	pick_sort(lst);
}
