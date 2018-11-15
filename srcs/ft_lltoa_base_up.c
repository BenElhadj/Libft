/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:09:33 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/14 20:15:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base_up(unsigned long long val, long base, int up)
{
	int64_t				len;
	unsigned long long	nbr;
	char				*ptr;
	char				*ret;
	char				*str;

	str = (up == 1 ? "0123456789ABCDEF" : "0123456789abcdef");
	if (val == 0)
		return ("0");
	len = 0;
	nbr = val;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	nbr = val;
	if (!(ptr = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ptr[len] = '\0';
	while (nbr)
		nbr ? (ptr[--len] = str[nbr % base]) && (nbr /= base) : 0;
	ret = ptr;
	free(ptr);
	return (ret);
}
