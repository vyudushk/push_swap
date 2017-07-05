/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/04 22:47:41 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	print_lst(t_list *lst)
{
	int		*i;

	i = lst->content;
	ft_putnbr(*i);
	ft_putchar('\n');
}

t_list	*arg_to_lst(int argc, char **argv)
{
	int		i;
	int		tmp;
	t_list	*lst;

	i = 1;
	tmp = 0;
	lst = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		ft_lstadd(&lst, ft_lstnew(&tmp, sizeof(int)));
		i++;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list	*lst;

	lst = arg_to_lst(argc, argv);
	ft_lstiter(lst, print_lst);
}
