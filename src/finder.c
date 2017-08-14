/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:45:18 by vyudushk          #+#    #+#             */
/*   Updated: 2017/08/13 19:48:02 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		peek(t_list *stk)
{
	int	*i;

	i = stk->content;
	return (*i);
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
