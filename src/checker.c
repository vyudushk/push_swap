/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/09/21 13:45:00 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

void	is_sort(t_list *lst, int len)
{
	int	*i;
	int	*next;

	if (ft_lstlen(lst) != len)
	{
		ft_putstr("KO\n");
		exit(0);
	}
	while (lst)
	{
		i = lst->content;
		if (lst->next)
			next = lst->next->content;
		else
		{
			ft_putstr("OK\n");
			exit(0);
		}
		if (*i > *next)
		{
			ft_putstr("KO\n");
			exit(0);
		}
		lst = lst->next;
	}
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*stack;
	char	*line;
	int		len;

	stack = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		lst = arg_to_lst(argc - 1, argv + 1);
		debug(lst, stack);
	}
	else
		lst = arg_to_lst(argc, argv);
	len = ft_lstlen(lst);
	while (get_next_line(0, &line))
	{
		if (isvalid(line) == 0)
			leave();
		operate(line, &lst, &stack);
		if (ft_strcmp(argv[1], "-v") == 0)
			debug(lst, stack);
		free(line);
	}
	is_sort(lst, len);
}
