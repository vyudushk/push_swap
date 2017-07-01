/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 20:54:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 22:13:36 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		hp(char *tmp, int fd, t_flag flags, const char **input)
{
	int	ret;

	ret = 0;
	if (flags.type == 'o' || flags.type == 'x' || flags.type == 'X')
		dealhash(&tmp, flags);
	if (**input == 'p')
		handle_p(&tmp);
	if (flags.type == 's')
	{
		if (tmp == NULL)
			ret += ft_printtab(fd, "(null)", flags);
		else
			ret += ft_printtab(fd, tmp, flags);
	}
	else
		ret += ft_printtab(fd, tmp, flags);
	if (flags.type != 's')
		free(tmp);
	(*input)++;
	return (ret);
}

int		cp(char c, int fd, t_flag flags, const char **input)
{
	int	ret;

	ret = 0;
	ret += ft_chartab(fd, flags.tab, c, flags);
	(*input)++;
	return (ret);
}
