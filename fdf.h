/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 04:51:56 by jandreu           #+#    #+#             */
/*   Updated: 2015/03/21 22:32:12 by jandreu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIDTH 2000
# define HEIGHT 1200

typedef struct		s_coord
{
	int				x;
	int				y;
	int				xpix;
	int				ypix;
	int				z;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_param
{
	int				h;
	int				l;
	int				zoom;
	float			altitude;
	int				x_start;
	int				y_start;
	void			*mlx;
	void			*win;
	int				zmax;
	int				zmin;
	int				xmax;
	int				ymax;
	int				color;
	float			angle;
	t_coord			*start;
}					t_param;

/*
**expose.c
*/
int					expose_hook(t_param *param);
int					key_hook(int keycode, t_param *param);

/*
**draw.c
*/
void				ft_draw(t_coord *pos1, t_coord *pos2, t_param *param);
void				ft_draw_direction(t_param *param);

/*
**ft_fdf.c
*/
t_coord				*ft_lstcreate(int x, int y, int z);
void				ft_addlst(t_param *param, t_coord *new);
void				ft_afflst(t_coord *start);

/*
**window.c
*/
void				ft_aff_win(t_param *param);
void				ft_pixel_put(t_param *param);
void				ft_getpix(t_param *param);

#endif
