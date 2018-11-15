/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 05:05:12 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/19 11:33:16 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define BUFF_SIZE 1

unsigned long	lenuntil(char *str, char c);
char			*ft_strjoin_until(char *s1, char *s2, char c, int i);
int				get_next_line(const int fd, char **line);

#endif
