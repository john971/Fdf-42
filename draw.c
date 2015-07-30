/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 01:30:23 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/21 22:13:36 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_coord *pos1, t_coord *pos2, t_param *param)
{
	if (pos1->z <= 0 && pos2->z <= 0)
		param->color = 0x000FFF;
	else if (pos1->z > 80 * param->zmax / 100 ||
			pos2->z > 80 * param->zmax / 100)
		param->color = 0xFEFDF0;
	else if (pos1->z > 55 * param->zmax / 100 ||
			pos2->z > 55 * param->zmax / 100)
		param->color = 0x87591A;
	else if (pos1->z > 40 * param->zmax / 100 ||
			pos2->z > 40 * param->zmax / 100)
		param->color = 0x568203;
	else
		param->color = 0x3A9D23;
	return (param->color);
}

void	ft_draw_line1(t_coord *pos1, t_coord *pos2, t_param *param)
{
	int x;
	int x1;
	int x2;
	int ypos;

	x = pos1->xpix;
	x1 = x;
	x2 = pos2->xpix;
	while (x < x2)
	{
		ypos = pos1->ypix + ((pos2->ypix - pos1->ypix) * (x - x1)) / (x2 - x1);
		ft_color(pos1, pos2, param);
		mlx_pixel_put(param->mlx, param->win, x, ypos, param->color);
		x++;
	}
}

void	ft_draw_line2(t_coord *pos1, t_coord *pos2, t_param *param)
{
	int y;
	int y1;
	int y2;
	int xpos;

	y = pos1->ypix;
	y1 = y;
	y2 = pos2->ypix;
	while (y < y2)
	{
		xpos = pos1->xpix + ((pos2->xpix - pos1->xpix) * (y - y1)) / (y2 - y1);
		ft_color(pos1, pos2, param);
		mlx_pixel_put(param->mlx, param->win, xpos, y, param->color);
		y++;
	}
}

void	ft_draw(t_coord *pos1, t_coord *pos2, t_param *param)
{
	int xpos;
	int ypos;

	if (pos2->xpix > pos1->xpix)
		xpos = pos2->xpix - pos1->xpix;
	else
		xpos = pos1->xpix - pos2->xpix;
	if (pos2->ypix > pos1->ypix)
		ypos = pos2->ypix - pos1->ypix;
	else
		ypos = pos1->ypix - pos2->ypix;
	if (xpos > ypos)
	{
		if (pos1->xpix < pos2->xpix)
			ft_draw_line1(pos1, pos2, param);
		else
			ft_draw_line1(pos2, pos1, param);
	}
	else
	{
		if (pos1->ypix < pos2->ypix)
			ft_draw_line2(pos1, pos2, param);
		else
			ft_draw_line2(pos2, pos1, param);
	}
}
