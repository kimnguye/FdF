/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:38:39 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:14:47 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_initial_view(t_mlx *param);
void	ft_iso_view(t_mlx *param);
void	ft_above_view(t_mlx *param);
void	ft_calc_view(t_mlx *param);

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
	param->view = 1;
	ft_erase_map(param);
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
	param->view = 0;
	ft_erase_map(param);
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
void	ft_calc_view(t_mlx *param)
{
	ft_erase_map(param);
	ft_copy_map(param->map, param->res, param);
	if (param->view)
		ft_transfo(param->map, param->res, param);
	else
		ft_zoom(param->map, param->res, param, param->zoom);
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

