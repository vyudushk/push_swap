/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/06 23:25:19 by vyudushk         ###   ########.fr       */
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

void	leave(void)
{
	ft_putstr("Error\n");
	exit(0);
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

t_list	*arg_to_lst(int argc, char **argv)
{
	int		i;
	int		tmp;
	t_list	*lst;

	i = 1;
	if (argc == 1)
		exit(0);
	tmp = 0;
	lst = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (isnumeric(argv[i]) == 0 || isduplicate(lst, tmp)
		|| ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			leave();
		ft_lstaddend(&lst, ft_lstnew(&tmp, sizeof(int)));
		i++;
	}
	return (lst);
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

void	is_sort(t_list *lst)
{
	int	*i;
	int	*next;

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
	char	*line;

	lst = arg_to_lst(argc, argv);
	ft_lstiter(lst, print_lst);
	while (get_next_line(0, &line))
	{
		if (isvalid(line) == 0)
			leave();
		free(line);
	}
	//handle the actual operations
	is_sort(lst);
}
