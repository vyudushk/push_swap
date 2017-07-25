/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 04:11:24 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 18:49:54 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_list **stack)
{
	t_list	*fir;
	t_list	*sec;

	if (!*stack && (*stack)->next)
		return ;
	fir = *stack;
	sec = (*stack)->next;
	fir->next = sec->next;
	sec->next = fir;
	*stack = sec;
}

void	push(t_list **src, t_list **dst)
{
	t_list	*hold;

	if (!*src)
		return ;
	hold = (*src)->next;
	(*src)->next = 0;
	ft_lstadd(dst, *src);
	*src = hold;
}

void	rotate(t_list **stack)
{
	t_list	*hold;

	if (*stack && (*stack)->next)
	{
		hold = *stack;
		*stack = (*stack)->next;
		hold->next = NULL;
		ft_lstaddend(stack, hold);
	}
}

void	rev_rotate(t_list **stack)
{
	t_list	*hold;
	t_list	*start;

	if (*stack && (*stack)->next)
	{
		hold = *stack;
		start = *stack;
		while (hold->next)
			hold = hold->next;
		ft_lstadd(stack, hold);
		while (start->next != hold)
			start = start->next;
		start->next = NULL;
	}
}

void	operate(char *cmd, t_list **astk, t_list **bstk)
{
	if (ft_strcmp(cmd, "sa") == 0 || ft_strcmp(cmd, "ss") == 0)
		swap(astk);
	if (ft_strcmp(cmd, "sb") == 0 || ft_strcmp(cmd, "ss") == 0)
		swap(bstk);
	if (ft_strcmp(cmd, "pa") == 0)
		push(bstk, astk);
	if (ft_strcmp(cmd, "pb") == 0)
		push(astk, bstk);
	if (ft_strcmp(cmd, "ra") == 0 || ft_strcmp(cmd, "rr") == 0)
		rotate(astk);
	if (ft_strcmp(cmd, "rb") == 0 || ft_strcmp(cmd, "rr") == 0)
		rotate(bstk);
	if (ft_strcmp(cmd, "rra") == 0 || ft_strcmp(cmd, "rrr") == 0)
		rev_rotate(astk);
	if (ft_strcmp(cmd, "rrb") == 0 || ft_strcmp(cmd, "rrr") == 0)
		rev_rotate(bstk);
}
