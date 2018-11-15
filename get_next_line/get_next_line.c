/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:02:31 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/19 11:22:46 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long	lenuntil(char *s1, char c)
{
	unsigned long i;

	i = 0;
	while (s1[i] != c && s1[i])
		i++;
	return (i);
}

int				move(char *str, char c)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != c && str[i])
		i++;
	c = str[i];
	if (str[i] == c)
	{
		i++;
		while (str[x + i])
		{
			str[x] = str[x + i];
			x++;
		}
		i = x + i;
		while (x < i)
			str[x++] = '\0';
	}
	if (c == '\0')
		return (0);
	return (1);
}

char			*ft_strjoin_until(char *s1, char *s2, char c, int i)
{
	int		x;
	char	*str;

	i = 0;
	x = 0;
	if (s1 && s2)
		str = malloc(sizeof(char) * (1 + ft_strlen(s1)) + lenuntil(s2, c));
	else if (!(s1))
		if (!(str = malloc(sizeof(char) * (1 + lenuntil(s2, c)))))
			return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x] && s2[x] != c)
		str[i++] = s2[x++];
	str[i] = '\0';
	free(s1);
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char	b[BUFF_SIZE + 1];
	int			i;
	char		*str;
	int			x;

	x = 0;
	i = -9;
	str = NULL;
	str = ft_strjoin_until(str, b, '\0', i);
	while ((lenuntil(b, '\n') == ft_strlen(b)) && (i == BUFF_SIZE || i == -9))
	{
		if ((i = read(fd, b, BUFF_SIZE)) == -1)
			return (-1);
		while (x + i != BUFF_SIZE)
			b[i + x++] = '\0';
		str = ft_strjoin_until(str, b, '\n', i);
	}
	if (i == -9)
		str = ft_strjoin_until(NULL, b, '\n', i);
	if (move(b, 10) == 1 && str == NULL && (*line = malloc(sizeof(char) * (1))))
		return (1);
	if (str == NULL)
		str = malloc(sizeof(char) * (1));
	*line = str;
	return ((*line)[0] ? 1 : 0);
}
