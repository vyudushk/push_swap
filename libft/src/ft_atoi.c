/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:31:06 by vyudushk          #+#    #+#             */
/*   Updated: 2017/07/05 23:38:42 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long	ft_atol(const char *str)
{
	int		i;
	size_t	num;
	int		isneg;

	i = 0;
	num = 0;
	isneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return (num * isneg);
}

int		ft_atoi(const char *str)
{
	int		i;
	size_t	num;
	int		isneg;

	i = 0;
	num = 0;
	isneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - 48;
		i++;
	}
	return (num * isneg);
}
