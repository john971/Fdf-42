/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 00:50:20 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/21 22:16:41 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int expose_hook(t_param *param)
{
	mlx_clear_window(param->mlx, param->win);
	ft_getpix(param);
	ft_draw_direction(param);
	return (0);
}

int key_hook(int keycode, t_param *param)
{
	if (keycode == 126)
		param->y_start -= 100;
	else if (keycode == 125)
		param->y_start += 100;
	else if (keycode == 123)
		param->x_start -= 100;
	else if (keycode == 124)
		param->x_start += 100;
	else if (keycode == 69)
		param->altitude += 0.2;
	else if (keycode == 78)
		param->altitude -= 0.2;
	else if (keycode == 12)
		param->zoom += param->zoom / 2;
	else if (keycode == 13)
		param->zoom -= param->zoom / 2;
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	expose_hook(param);
	return (0);
}
