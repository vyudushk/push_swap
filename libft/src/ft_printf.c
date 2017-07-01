/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:39:37 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/01 02:13:27 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

#define ITA ft_itoa_base
#define UITA ft_uitoa_base

size_t	count(const char *input, int *tab)
{
	size_t	ret;

	ret = 0;
	while (*input >= '0' && *input <= '9')
	{
		*tab = *tab * 10;
		*tab = *tab + (*input - '0');
		input++;
		ret++;
	}
	return (ret);
}

size_t	collecting(const char **input, t_flag *flags, t_length *len)
{
	const char	*hold;

	hold = *input;
	flags->percent = 1;
	(*input)++;
	*input += handle_flags(*input, flags);
	*input += count(*input, &flags->tab);
	if (**input == '.' && (flags->dot = 1) && ((*input)++))
		*input += count(*input, &flags->pres);
	(*input) += handle_len(*input, len);
	return (*input - hold);
}

void	do_spec(t_flag f, const char **i, int *r, va_list a)
{
	if ((((**i == 's' || **i == 'S') && (f.type = 's')) && (*r += hp(va_arg(a,
char*), f.fd, f, i))) || ((**i == 'p') && (r += hp(UITA((size_t)va_arg(a,
void*), 16, 0), f.fd, f, i))) || ((**i == 'd' || **i == 'i') && (r += hp(ITA(
c(f.len, va_arg(a, intmax_t)), 10, 1, f), f.fd, f, i))) || ((**i == 'D') &&
(r += hp(ITA((long)va_arg(a, intmax_t), 10, 1, f), f.fd, f, i))) ||
((**i == 'o' && (f.type = 'o')) && (r += hp(UITA(uc(f.len, va_arg(a, uintmax_t)
), 8, 0), f.fd, f, i))) || ((**i == 'u') && (r += hp(UITA(uc(f.len, va_arg(a,
uintmax_t)), 10, 0), f.fd, f, i))) || ((**i == 'U') && (r += hp(UITA((long)
va_arg(a, uintmax_t), 10, 0), f.fd, f, i))) || ((**i == 'x' &&
(f.type = 'x')) && (r += hp(UITA(uc(f.len, va_arg(a, uintmax_t)),
16, 0), f.fd, f, i))) ||
((**i == 'X' && (f.type = 'X')) && (r += hp(UITA(uc(f.len, va_arg(a,
uintmax_t)), 16, 1), f.fd, f, i))) || ((**i == 'c' || **i == 'C') &&
(r += cp((char)va_arg(a, int), f.fd, f, i))) ||
((**i == '%' && f.percent == 1) && (r += cp('%', f.fd, f, i))))
		return ;
}

int		start_print(int fd, const char *input, va_list args)
{
	t_flag		flags;
	int			ret;

	ret = 0;
	clear_flags(&flags);
	flags.fd = fd;
	while (*input)
	{
		if (*input == '%')
		{
			collecting(&input, &flags, &flags.len);
			do_spec(flags, &input, &ret, args);
			continue ;
		}
		else if (*input)
		{
			clear_flags(&flags);
			ft_putchar_fd(*input, fd);
			ret++;
		}
		if (*input == '\0')
			break ;
		input++;
	}
	return (ret);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;

	va_start(args, input);
	return (start_print(1, input, args));
}
