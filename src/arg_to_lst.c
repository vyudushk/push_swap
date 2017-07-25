/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:57:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/24 17:38:41 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpush.h"
#include <stdlib.h>

int		isnumeric_str(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if ((*str > '9' || *str < '0') && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

t_list	*str_to_lst(char *str)
{
	int		tmp;
	t_list *lst;

	tmp = 0;
	lst = 0;
	while (*str)
	{
		tmp = ft_atoi(str);
		if (isnumeric_str(str) == 0 || isduplicate(lst, tmp) ||
			ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
			leave();
		ft_lstaddend(&lst, ft_lstnew(&tmp, sizeof(int)));
		while (*str >= '0' && *str <= '9')
			str++;
		while (*str == ' ')
			str++;
	}
	if (ft_lstlen(lst) == 1)
		exit(0);
	return (lst);
}

t_list	*arg_to_lst(int argc, char **argv)
{
	int		i;
	int		tmp;
	t_list	*lst;

	i = 1;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		return (str_to_lst(argv[1]));
	tmp = 0;
	lst = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (isnumeric(argv[i]) == 0 || isduplicate(lst, tmp) ||
			ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			leave();
		ft_lstaddend(&lst, ft_lstnew(&tmp, sizeof(int)));
		i++;
	}
	return (lst);
}

