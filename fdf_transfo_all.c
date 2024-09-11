/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transfo_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:31:38 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/11 23:04:42 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trans(t_map *maps, t_mlx *vars);
void	ft_center_and_trans(t_map *maps, t_mlx *vars, int code);
void	ft_transfo(t_map *map, t_map *res, t_mlx *vars);
void	ft_margin(t_map *maps, t_mlx *vars);
/* ft_zoom(param->map, param->res, param, param->zoom);
	ft_altitude(param->res, param);
	ft_iso(param->res, param->rot_iso, param);*/
void	ft_transfo(t_map *map, t_map *res, t_mlx *vars)
{
	int		i;
	float	rad;
	int		tmp_x;
	int		tmp_y;

	rad = de_to_rad(vars->rot_iso);
	i = 0;
	while (i < vars->max)
	{
		tmp_x = map->x[i] * vars->zoom;
		tmp_y = map->y[i] * vars->zoom;
		if (res->z[i])
			res->z[i] = map->z[i] * (vars->zoom * 0.2) * vars->altitude;
		res->x[i] = (tmp_x - tmp_y) * cos(rad);
		res->y[i] = (tmp_x + tmp_y) * sin(rad) - res->z[i];
		i++;
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
/*centers the maps AND applies a translation to the drawing*/
void	ft_center_and_trans(t_map *maps, t_mlx *vars, int code)
{
	int		i;
	int		add_x;
	int		add_y;

	add_x = vars->trans_x;
	add_y = vars->trans_y;
	if (code == ROT_CODE)
	{
		add_x = 0;
		add_y = 0;
	}
	ft_margin(maps, vars);
	i = 0;
	while (i < vars->max)
	{
		maps->x[i] += vars->margin_x + add_x;
		maps->y[i] += vars->margin_y + add_y;
		i++;
	}
	vars->center_x += vars->trans_x;
	vars->center_y += vars->trans_y;
	return ;
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
		res->z[i] = map->z[i] * (zoom * 0.2);
		i++;
	}
}

/*applies the isometric projection*/
void	ft_iso(t_map *maps, int degree, t_mlx *vars)
{
	int			i;
	int			tmp;
	float		rad;

	rad = de_to_rad(degree);
	i = 0;
	while (i < vars->max)
	{
		tmp = maps->x[i];
		maps->x[i] = (tmp - maps->y[i]) * cos(rad);
		maps->y[i] = (tmp + maps->y[i]) * sin(rad) - maps->z[i];
		i++;
	}
}
