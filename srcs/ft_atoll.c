/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:15:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/14 20:15:14 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(char *str)
{
	long long	result;
	int			sign;
	long		i;

	result = 0;
	sign = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\v') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-result);
	else
		return (result);
}
