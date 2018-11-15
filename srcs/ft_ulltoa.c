/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 03:08:10 by bhamdi            #+#    #+#             */
/*   Updated: 2018/11/14 20:16:28 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char					*mall;
	char					*ret;
	unsigned long long		temp_n;
	int						len;

	len = 2;
	temp_n = n;
	while (n)
		(n = n / 10) ? len++ : 0;
	n = temp_n;
	if ((mall = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	mall[len--] = '\0';
	mall[len--] = n % 10 + '0';
	while ((n = n / 10))
		mall[len--] = n % 10 + '0';
	ret = mall;
	free(mall);
	return (ret);
}
