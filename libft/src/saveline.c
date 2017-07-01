/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 03:32:56 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/01 02:14:21 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	usave_line(uintmax_t *val, uintmax_t value, int *i)
{
	*val = value;
	*i = 0;
}

void	save_line(intmax_t *val, intmax_t *value, int *i)
{
	*val = *value;
	*i = 0;
	if (*value < 0)
		*value = *value * -1;
}

int		string_dot(t_flag *flags, char *str, int ret, int fd)
{
	if (flags->tabside == 1 && flags->type == 's' && flags->dot == 1)
	{
		ft_putnstr_fd(str, flags->pres, fd);
		flags->tab += ft_strlen(str) - flags->pres;
		ret = ret - ft_strlen(str) + flags->pres;
	}
	else if (flags->tabside == 0 && flags->type == 's'
			&& flags->dot == 1 && *str != 0)
	{
		ft_putnstr_fd(str, flags->pres, fd);
		flags->tab += ft_strlen(str) - flags->pres;
		ret = ret - ft_strlen(str) + flags->pres;
	}
	else
		ft_putstr_fd(str, fd);
	return (ret);
}

size_t	handle_len(const char *input, t_length *len)
{
	size_t	count;

	count = 0;
	while (*input == 'h' || *input == 'l' || *input == 'j' || *input == 'z')
	{
		len->h += (*input == 'h') ? 1 : 0;
		len->l += (*input == 'l') ? 1 : 0;
		len->j += (*input == 'j') ? 1 : 0;
		len->z += (*input == 'z') ? 1 : 0;
		input++;
		count++;
	}
	return (count);
}

size_t	handle_flags(const char *input, t_flag *flags)
{
	size_t	count;

	count = 0;
	while (*input == '-' || *input == '+' || *input == '#' || *input == '0'
			|| *input == ' ')
	{
		if (*input == '-' && flags->zerotab == 0)
			flags->tabside = BACK;
		else
			flags->tabside = FRONT;
		flags->plus += (*input == '+') ? 1 : 0;
		flags->space += (*input == ' ') ? 1 : 0;
		flags->hash += (*input == '#') ? 1 : 0;
		if (*input == '0')
		{
			flags->zerotab = 1;
			flags->tabside = FRONT;
		}
		input++;
		count++;
	}
	return (count);
}
