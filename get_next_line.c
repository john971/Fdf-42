/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:33:20 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/20 21:39:18 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

static int		ft_linechr(char *tamp, size_t i)
{
	while (tamp[i])
	{
		if (tamp[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int		test(int ret, char **tamp)
{
	if (ret == 0 && **tamp)
	{
		ft_strdel(tamp);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	static char	*tamp = NULL;
	char		buff[BUFF_SIZE];
	size_t		i;

	i = 0;
	if (BUFF_SIZE > 100000)
		return (0);
	if (tamp == NULL)
		tamp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tamp = ft_strjoin(tamp, buff);
		i = ft_linechr(tamp, i);
		if (i > 0 || tamp[i] == '\n')
		{
			*line = ft_strsub(tamp, 0, (i));
			tamp = ft_strsub(tamp, (i + 1), ft_strlen(tamp + i + 1));
			return (1);
		}
	}
	*line = ft_strsub(tamp, 0, ft_strlen(tamp));
	return (test(ret, &tamp));
}
