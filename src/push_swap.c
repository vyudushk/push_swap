/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 17:29:47 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

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

t_list	*copy_lst(t_list *input)
{
	t_list *ret;

	ret = ft_lstnew(input->content, input->content_size);
	return (ret);
}

int		find_smallest(t_list *input)
{
	int		*i;
	int		*hold;
	t_list	*stk;

	stk = ft_lstmap(input, copy_lst);
	i = stk->content;
	while (stk)
	{
		hold = stk->content;
		if (*hold < *i)
			*i = *hold;
		stk = stk->next;
	}
	return (*i);
}

int		peek(t_list *stk)
{
	int	*i;

	i = stk->content;
	return (*i);
}

void	sort(t_list *astk)
{
	t_list	*bstk;
	int		len;
	int		small;
	int		hold;

	len = ft_lstlen(astk);
	bstk = 0;
	while (ft_lstlen(bstk) < len)
	{
		hold = peek(astk);
		small = find_smallest(astk);
		if (hold == small)
		{
			operate("pb", &astk, &bstk);
			ft_putstr("pb\n");
		}
		else
		{
			operate("ra", &astk, &bstk);
			ft_putstr("ra\n");
		}
	}
	while (len)
	{
		operate("pa", &astk, &bstk);
		ft_putstr("pa\n");
		len--;
	}
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
