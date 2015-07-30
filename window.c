/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 18:32:08 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/21 22:20:13 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*ft_coord_chr(t_coord *start)
{
	t_coord *curseur;

	curseur = start;
	while (curseur && curseur->y == start->y)
		curseur = curseur->next;
	while (curseur && curseur->x != start->x)
		curseur = curseur->next;
	if (curseur && curseur->y == start->y + 1)
		return (curseur);
	return (NULL);
}

void		ft_draw_direction(t_param *param)
{
	t_coord *curseur;

	curseur = param->start;
	while (curseur)
	{
		if ((curseur && curseur->next) && (curseur->y == curseur->next->y))
			ft_draw(curseur, curseur->next, param);
		if (curseur && ft_coord_chr(curseur))
			ft_draw(curseur, ft_coord_chr(curseur), param);
		curseur = curseur->next;
	}
}

void		ft_aff_win(t_param *param)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "fdf");
	mlx_key_hook(param->win, key_hook, param);
	mlx_expose_hook(param->win, expose_hook, param);
	mlx_loop(param->mlx);
}

void		ft_getpix(t_param *param)
{
	t_coord *curseur;
	int		tmp;
	int		tmp2;

	param->angle = M_PI / 8;
	if (param->start)
	{
		curseur = param->start;
		while (curseur)
		{
			curseur->ypix = param->zoom * (curseur->y - param->ymax / 2);
			curseur->xpix = param->zoom * (curseur->x - param->xmax / 2);
			tmp = curseur->xpix * cos(param->angle) - curseur->ypix *
				sin(param->angle);
			tmp2 = curseur->xpix * sin(param->angle) + curseur->ypix *
				cos(param->angle);
			curseur->ypix = tmp2 + ((param->zoom * param->ymax / 2) -
							(curseur->z * param->altitude)) + param->y_start;
			curseur->xpix = tmp + (param->zoom * param->xmax / 2) +
				param->x_start;
			curseur = curseur->next;
		}
	}
}
