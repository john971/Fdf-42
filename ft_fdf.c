/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:21:30 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/21 22:42:25 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_filling(char *line, int y, t_param *param)
{
	int		i;
	int		x;
	char	**map;
	int		z;

	i = 0;
	x = 0;
	z = 0;
	map = ft_strsplit(line, ' ');
	while (map[i])
	{
		if (param->xmax < x)
			param->xmax = x;
		if (param->ymax < y)
			param->ymax = y;
		z = ft_atoi(map[i]);
		if (z > param->zmax)
			param->zmax = z;
		else if (z < param->zmin)
			param->zmin = z;
		ft_addlst(param, ft_lstcreate(x, y, z));
		x++;
		i++;
	}
}

t_coord		*ft_lstcreate(int x, int y, int z)
{
	t_coord *new;

	new = malloc(sizeof(t_coord));
	new->y = y;
	new->x = x;
	new->z = z;
	new->xpix = 0;
	new->ypix = 0;
	new->next = NULL;
	return (new);
}

void		ft_addlst(t_param *param, t_coord *new)
{
	t_coord	*curseur;

	if (param->start)
	{
		curseur = param->start;
		while (curseur && curseur->next)
			curseur = curseur->next;
		curseur->next = new;
	}
	else
		param->start = new;
}

void		ft_param_init(t_param *param)
{
	param->xmax = 0;
	param->ymax = 0;
	param->start = NULL;
	param->x_start = WIDTH * 0.2;
	param->y_start = HEIGHT * 0.2;
	param->altitude = 0.1;
	param->color = 0xFFFFFF;
	param->zmin = 0;
	param->zmax = 0;
}

int			main(int ac, char **av)
{
	int		fd;
	t_param *param;
	char	*line;
	int		y;

	y = -1;
	param = malloc(sizeof(t_param));
	ft_param_init(param);
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (0);
	if (fd == -1)
		ft_putendl_fd("ouverture impossible", 2);
	else
	{
		while (get_next_line(fd, &line))
			ft_filling(line, y++, param);
		param->zoom = WIDTH * 0.6 / param->xmax;
		ft_aff_win(param);
		close(fd);
	}
	return (0);
}
