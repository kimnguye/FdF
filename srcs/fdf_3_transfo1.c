/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transfo1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:31:38 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:11:25 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_center_and_trans(t_map *maps, t_mlx *vars);
void	ft_transfo(t_map *map, t_map *res, t_mlx *vars);
void	ft_margin(t_map *maps, t_mlx *vars);
void	ft_zoom(t_map *map, t_map *res, t_mlx *vars, float zoom);

/* ft_zoom, ft_altitude, ft_iso
view 0 = from the top, view 1 = iso*/
void	ft_transfo(t_map *map, t_map *res, t_mlx *vars)
{
	int		i;
	float	rad;
	int		tmp_x;
	int		tmp_y;

	rad = de_to_rad(vars->rot_iso);
	i = -1;
	while (++i < vars->max)
	{
		tmp_x = map->x[i] * vars->zoom;
		tmp_y = map->y[i] * vars->zoom;
		if (res->z[i])
			res->z[i] = map->z[i] * (vars->zoom * 0.2) * vars->altitude;
		res->x[i] = (tmp_x - tmp_y) * cos(rad);
		res->y[i] = (tmp_x + tmp_y) * sin(rad) - res->z[i];
	}
}

void	ft_margin(t_map *maps, t_mlx *vars)
{
	int		x_margin;
	int		y_margin;
	t_point	*xtrem;

	xtrem = ft_extrem_values(maps, vars);
	x_margin = (WIDTH - xtrem->max_x + xtrem->min_x) / 2 - xtrem->min_x;
	y_margin = (HEIGHT - xtrem->max_y + xtrem->min_y) / 2 - xtrem->min_y;
	free (xtrem);
	vars->margin_x = x_margin;
	vars->margin_y = y_margin;
}

/*applies a zoom of +/- 5% to the drawing*/
void	ft_zoom(t_map *map, t_map *res, t_mlx *vars, float zoom)
{
	int	i;

	i = 0;
	while (i < vars->max)
	{
		res->x[i] = map->x[i] * zoom;
		res->y[i] = map->y[i] * zoom;
		res->z[i] = map->z[i] * (zoom * 0.2) * vars->altitude;
		i++;
	}
}

/*centers the maps AND applies a translation to the drawing*/
void	ft_center_and_trans(t_map *maps, t_mlx *vars)
{
	int		i;
	int		add_x;
	int		add_y;

	add_x = vars->trans_x;
	add_y = vars->trans_y;
	ft_margin(maps, vars);
	i = 0;
	while (i < vars->max)
	{
		maps->x[i] += vars->margin_x + add_x;
		maps->y[i] += vars->margin_y + add_y;
		i++;
	}
	return ;
}
