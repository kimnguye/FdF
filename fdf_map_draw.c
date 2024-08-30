/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:10:22 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 18:17:32 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_map *maps, t_mlx *vars);

// void	ft_draw_line(int x, int y, t_mlx *param)
// {
// 	static t_point	*point_a;
// 	t_point			*point_b;

// 	if (point_a)
// 	{
// 		point_b = ft_point_new(x, y, 0, GREEN);
// 		ft_printf("A(%i; %i), B(%i, %i)",
// 			point_a->x, point_a->y, point_b->x, point_b->y);
// 		ft_segment(maps, point_a, point_b, param);
// 		free(point_a);
// 		point_a = NULL;
// 		free(point_b);
// 	}
// 	else
// 	{
// 		point_a = ft_point_new(x, y, 0, BLUE);
// 		ft_put_pixel_to_img(param, x, y, point_a->color);
// 	}
// 	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
// }

/*trace the segment between two given points a(x,y,z) and b(x',y',z') */
void	ft_segment(t_map *maps, int a, int b, t_mlx *vars)
{
	t_slope	*ab;

	ab = malloc(sizeof(t_slope));
	ab->dx = (maps->x[b] - maps->x[a]);
	ab->dy = (maps->y[b] - maps->y[a]);
	ab->i = maps->x[a];
	ab->j = maps->y[a];
	ab->p = 0;
	if (ab->dx == 0)
		ft_segment_vertical (maps, a, b, vars, ab);
	else if (ab->dy >= 0 && ab->dx > 0)
		ft_segment_q1(maps, a, b, vars, ab);
	else if (ab->dy >= 0 && ab->dx < 0)
		ft_segment_q2(maps, a, b, vars, ab);
	else if (ab->dy < 0 && ab->dx < 0)
		ft_segment_q3(maps, a, b, vars, ab);
	else if (ab->dy < 0 && ab->dx > 0)
		ft_segment_q4(maps, a, b, vars, ab);
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
	ft_draw_map(vars->res, vars);
}

/*draw the map in the img
assuming the map is a rectangle*/
void	ft_draw_map(t_map *maps, t_mlx *vars)
{
	int	i;

	i = 0;
	while (i / vars->max_x < vars->max_y - 1)
	{
		while (i % vars->max_x < vars->max_x - 1)
		{
			ft_segment(maps, i, i + 1, vars);
			ft_segment(maps, i, i + vars->max_x, vars);
			i++;
		}
		ft_segment(maps, i, i + vars->max_x, vars);
		i++;
	}
	i = 0;
	while (i < vars->max_x - 1)
	{
		ft_segment(maps, i, i + 1, vars);
		i++;
	}
}
