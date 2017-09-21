/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 13:15:39 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

void	finish_sort(t_list *astk, t_list *bstk)
{
	t_list	*acpy;
	t_list	*bcpy;
	int		hard;
	int		soft;

	while (ft_lstlen(bstk) && ft_lstlen(astk) == 0)
		if (peek(bstk) == find_biggest(bstk))
			poperate("pa", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) >= ft_lstlen(bstk) / 2)
			poperate("rrb", &astk, &bstk);
		else if (position(find_biggest(bstk), bstk) < ft_lstlen(bstk) / 2)
			poperate("rb", &astk, &bstk);
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

void	sort_big(t_list *astk, t_list *bstk, int avg)
{
	while (any_below(astk, avg))
		if (peek(astk) <= avg)
			poperate("pb", &astk, &bstk);
		else if (position_avg(avg, astk, 0) >= ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (position_avg(avg, astk, 0) < ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
	avg = find_avg(bstk);
	while (any_above(bstk, avg))
		if (peek(bstk) >= avg)
			poperate("pa", &astk, &bstk);
		else if (position_avg(avg, bstk, 1) >= (ft_lstlen(bstk) / 2))
			poperate("rrb", &astk, &bstk);
		else if (position_avg(avg, bstk, 1) < (ft_lstlen(bstk) / 2))
			poperate("rb", &astk, &bstk);
	avg = find_avg(astk);
	while ((any_below(astk, avg) && !is_sort_push(astk)) ||
			(any_below(astk, avg) == 0 && (avg = find_avg(astk))))
		if (peek(astk) <= avg)
			poperate("pb", &astk, &bstk);
		else if (position_avg(avg, astk, 0) >= ft_lstlen(astk) / 2)
			poperate("rra", &astk, &bstk);
		else if (position_avg(avg, astk, 0) < ft_lstlen(astk) / 2)
			poperate("ra", &astk, &bstk);
	finish_sort(astk, bstk);
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	if (is_sort_push(lst))
		return (0);
	pick_sort(lst);
}
