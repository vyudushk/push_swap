/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 05:54:13 by vyudushk          #+#    #+#             */
/*   Updated: 2017/08/13 19:41:56 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sort_push(t_list *lst)
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

int		isnumeric(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

int		isduplicate(t_list *lst, int check)
{
	int	*i;

	while (lst)
	{
		i = lst->content;
		if (check == *i)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		isvalid(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
	|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
	|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
	|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
	|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
	|| ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}
