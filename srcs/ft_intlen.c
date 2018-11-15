/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:12:26 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/14 20:16:10 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(unsigned long long n)
{
	int		i;

	i = 0;
	n <= 0 ? i++ : 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
