/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:39:19 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/14 20:15:33 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long n)
{
	char			*mall;
	char			*ret;
	long long		temp_n;
	long			len;
	char			sign;

	if (n == INT64_MIN)
		return ("9223372036854775808");
	if (n == INT_MIN)
		return ("2147483648");
	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		len++;
	n = temp_n;
	if ((mall = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	mall[len--] = '\0';
	mall[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		mall[len--] = sign * (n % 10) + '0';
	sign < 0 ? (mall[len] = '-') : 0;
	(ret = mall) ? free(mall) : 0;
	return (mall);
}
