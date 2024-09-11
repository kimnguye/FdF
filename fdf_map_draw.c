/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:10:22 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/12 00:13:58 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_mlx *vars);

void	ft_draw_line(int x, int y, t_mlx *param)
{
	static int a[4];
	int			b[3];

	if (a[3])
	{
		b[0] = x;
		b[1] = y;
		b[2] = GREEN;
		ft_printf("A(%i; %i), B(%i, %i)", a[0], a[1], x, y);
		ft_pixel_to_img(param, x, y, b[2]);
		a[3] = 0;
	}
	else
	{
		a[0] = x;
		a[1] = y;
		a[2] = BLUE;
		a[3] = 1;
		ft_pixel_to_img(param, x, y, a[2]);
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
}

/*trace the segment between two given points a(x,y,z) and b(x',y',z') */
void	ft_segment(int a, int b, t_mlx *vars)
{
	t_slope	*ab;

	ab = malloc(sizeof(t_slope));
	ab->dx = (vars->res->x[b] - vars->res->x[a]);
	ab->dy = (vars->res->y[b] - vars->res->y[a]);
	ab->i = vars->res->x[a];
	ab->j = vars->res->y[a];
	ab->p = 0;
	if (ab->dx == 0)
		ft_segment_vertical (a, b, vars, ab);
	else if (ab->dy >= 0 && ab->dx > 0)
		ft_segment_q1(a, b, vars, ab);
	else if (ab->dy >= 0 && ab->dx < 0)
		ft_segment_q2(a, b, vars, ab);
	else if (ab->dy < 0 && ab->dx < 0)
		ft_segment_q3(a, b, vars, ab);
	else if (ab->dy < 0 && ab->dx > 0)
		ft_segment_q4(a, b, vars, ab);
	free(ab);
}

/*puts the res in black*/
void	ft_black_map(t_mlx *vars)
{
	int	i;

	i = 0;
	while (i < vars->max)
	{
		vars->res->color[i] = BLACK;
		i++;
	}
	ft_draw_map(vars);
}

/*draw the map in the img
assuming the map is a rectangle*/
void	ft_draw_map(t_mlx *vars)
{
	int	i;

	i = 0;
	while (i / vars->max_x < vars->max_y - 1)
	{
		while (i % vars->max_x < vars->max_x - 1)
		{
			ft_segment(i, i + 1, vars);
			ft_segment(i, i + vars->max_x, vars);
			i++;
		}
		ft_segment(i, i + vars->max_x, vars);
		i++;
	}
	while (i < vars->max - 1)
	{
		ft_segment(i, i + 1, vars);
		i++;
	}
}
