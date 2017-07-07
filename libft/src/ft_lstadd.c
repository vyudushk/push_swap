/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:49:39 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/06 22:13:20 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstaddend(t_list **head, t_list *new)
{
	t_list	*hold;

	if (*head)
	{
		hold = *head;
		while ((*head)->next)
			*head = (*head)->next;
		(*head)->next = new;
		*head = hold;
	}
	else
		*head = new;
}
