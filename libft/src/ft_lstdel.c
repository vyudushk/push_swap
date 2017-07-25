/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:40:32 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 18:07:42 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void   del(void *point, size_t n)
{
	ft_bzero(point, n);
	free(point);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp->next)
		ft_lstdel(&tmp->next, del);
	if (!tmp->next)
		del(tmp->content, tmp->content_size);
	free(*alst);
	*alst = NULL;
}
