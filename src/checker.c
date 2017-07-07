/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:43:29 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/07 03:49:09 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_lstlen(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print_lst(t_list *lst)
{
	int		*i;

	i = lst->content;
	ft_putnbr(*i);
	ft_putchar(' ');
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
	if (ft_strcmp(cmd, "sa") == 0)
		swap(astk);
	if (ft_strcmp(cmd, "sb") == 0)
		swap(bstk);
	if (ft_strcmp(cmd, "ss") == 0)
	{
		swap(astk);
		swap(bstk);
	}
	if (ft_strcmp(cmd, "pa") == 0)
		push(bstk, astk);
	if (ft_strcmp(cmd, "pb") == 0)
		push(astk, bstk);
	if (ft_strcmp(cmd, "ra") == 0)
		rotate(astk);
	if (ft_strcmp(cmd, "rb") == 0)
		rotate(bstk);
	if (ft_strcmp(cmd, "rr") == 0)
	{
		rotate(astk);
		rotate(bstk);
	}
	if (ft_strcmp(cmd, "rra") == 0)
		rev_rotate(astk);
	if (ft_strcmp(cmd, "rrb") == 0)
		rev_rotate(bstk);
	if (ft_strcmp(cmd, "rrr") == 0)
	{
		rev_rotate(astk);
		rev_rotate(bstk);
	}
}

void	debug(t_list *lst, t_list *stack)
{
	ft_putnbr(ft_lstlen(lst));
	ft_putstr(" A : ");
	ft_lstiter(lst, print_lst);
	ft_putchar('\n');
	ft_putnbr(ft_lstlen(stack));
	ft_putstr(" B : ");
	ft_lstiter(stack, print_lst);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*stack;
	char	*line;
	int		len;

	lst = arg_to_lst(argc, argv);
	stack = 0;
	debug(lst, stack);
	len = ft_lstlen(lst);
	while (get_next_line(0, &line))
	{
		if (isvalid(line) == 0)
			leave();
		operate(line, &lst, &stack);
		debug(lst, stack);
		free(line);
	}
	//handle the actual operations
	is_sort(lst, len);
}
