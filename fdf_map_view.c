/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:39 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/11 17:42:53 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_extrem_values(t_map *maps, t_mlx *vars);

/*put the initial view (iso projection)*/
void	ft_initial_view(t_mlx *param)
{
	ft_init_param_view(param);
	ft_transfo(param->map, param->res, param);
	ft_center_and_trans(param->res, param);
	ft_draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	ft_printf("zoom:%i%%; rot iso:%i°; map center (%i, %i);\n",
		(int)((param->zoom / ZOOM_INIT) * 100),
		param->rot_iso, param->center_x, param->center_y);
}

void	ft_iso_view(t_mlx *param)
{
	ft_black_map(param);
	ft_copy_map(param->map, param->res, param);
	param->rot_iso = ANGLE_INIT;
	param->rot_x = 0;
	param->rot_y = 0;
	param->rot_z = 0;
	ft_transfo(param->map, param->res, param);
	ft_center_and_trans(param->res, param);
	ft_draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	ft_printf("zoom:%i%%; rot iso:%i°; map center (%i, %i);",
		(int)((param->zoom / ZOOM_INIT) * 100),
		abs(param->rot_iso % 360), param->center_x, param->center_y);
	ft_printf("\nrot x:%i°; rot y:%i°; rot z:%i°;\n",
		abs(param->rot_x % 360), abs(param->rot_y % 360),
		abs(param->rot_z % 360));
}

void	ft_above_view(t_mlx *param)
{
	ft_black_map(param);
	ft_copy_map(param->map, param->res, param);
	ft_zoom(param->map, param->res, param, param->zoom);
	ft_center_and_trans(param->res, param);
	ft_draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	ft_printf("zoom:%i%%; rot iso:%i°; map center (%i, %i);",
		(int)((param->zoom / ZOOM_INIT) * 100),
		abs(param->rot_iso % 360), param->center_x, param->center_y);
	ft_printf("\nrot x:%i°; rot y:%i°; rot z:%i°;\n",
		abs(param->rot_x % 360), abs(param->rot_y % 360),
		abs(param->rot_z % 360));
}

/*applies the translation or zoom to map*/
void	ft_calc_view(t_mlx *param, int code)
{
	ft_black_map(param);
	ft_copy_map(param->map, param->res, param);
	ft_transfo(param->map, param->res, param);
	if (code != ROT_CODE)
		ft_center_and_trans(param->res, param);
	ft_rotate(param->res, param);
	ft_draw_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	ft_printf("zoom:%i%%; rot iso:%i°; map center (%i, %i);\n",
		(int)((param->zoom / ZOOM_INIT) * 100),
		abs(param->rot_iso % 360), param->center_x, param->center_y);
}
	// ft_printf("rot : x:%i°, y:%i°, z:%i°\n",
	// 	abs(param->rot_x % 360), abs(param->rot_y % 360),
	// 	abs(param->rot_z % 360));

/*returns the extreme values : x_min, y_min, x_max and y_max*/
t_point	*ft_extrem_values(t_map *maps, t_mlx *vars)
{
	int		i;
	t_point	*max_val;

	max_val = ft_point_new(maps->x[0], maps->x[0],
			maps->y[0], maps->y[0]);
	i = -1;
	while (++i < vars->max)
	{
		if (maps->x[i] > max_val->max_x)
			max_val->max_x = maps->x[i];
		if (maps->x[i] < max_val->min_x)
			max_val->min_x = maps->x[i];
		if (maps->y[i] > max_val->max_y)
			max_val->max_y = maps->y[i];
		if (maps->y[i] < max_val->min_x)
			max_val->min_x = maps->y[i];
	}
	return (max_val);
}
