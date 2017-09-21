/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:51:11 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 12:53:26 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

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

int		soft_end_test(t_list *astk, t_list *bstk)
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
		while (ft_lstlen(bstk) && peek_last(astk)
				< peek(astk) && peek_last(astk) > peek(bstk))
		{
			if (peek_last(astk))
				poperate("rra", &astk, &bstk);
		}
	}
	while (peek(astk) != find_smallest(astk))
		poperate("rra", &astk, &bstk);
}

int		hard_end_test(t_list *astk, t_list *bstk)
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
		while (ft_lstlen(bstk) && peek_last(astk)
				< peek(astk) && peek_last(astk) > peek(bstk))
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
