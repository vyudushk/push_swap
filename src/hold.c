/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:38:24 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 12:39:27 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

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
