/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:33:18 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/01 02:15:09 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		clear_len(t_length *len)
{
	len->h = 0;
	len->l = 0;
	len->j = 0;
	len->z = 0;
}

void		clear_flags(t_flag *flags)
{
	flags->tabside = 0;
	flags->zerotab = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->percent = 0;
	flags->type = 0;
	flags->dot = 0;
	flags->pres = 0;
	flags->tab = 0;
	flags->type = 0;
	clear_len(&flags->len);
}

intmax_t	c(t_length len, intmax_t castme)
{
	if (len.j)
		return ((intmax_t)castme);
	else if (len.h > 1)
		return ((char)castme);
	else if (len.h == 1)
		return ((short)castme);
	else if (len.l == 1)
		return ((long)castme);
	else if (len.l > 1)
		return ((long long)castme);
	else if (len.z)
		return ((size_t)castme);
	else
		return ((int)castme);
}

uintmax_t	uc(t_length len, uintmax_t castme)
{
	if (len.h > 1)
		return ((unsigned char)castme);
	else if (len.h == 1)
		return ((unsigned short)castme);
	else if (len.l == 1)
		return ((unsigned long)castme);
	else if (len.l > 1)
		return ((unsigned long long)castme);
	else if (len.j)
		return ((uintmax_t)castme);
	else if (len.z)
		return ((size_t)castme);
	else
		return ((unsigned int)castme);
}

int			ifprefix(t_flag flags, char c)
{
	return (flags.zerotab &&
	(c == '+' || (c == '0' && !flags.dot) || c == 'x' || c == 'X'));
}
