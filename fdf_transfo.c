/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 00:07:00 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 17:49:53 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_map *map, t_map *res, t_mlx *vars, float zoom);
void	ft_trans(t_map *maps, t_mlx *vars);
void	ft_center(t_map *maps, t_mlx *vars);
void	ft_iso(t_map *maps, int degree, t_mlx *vars);
void	ft_altitude(t_map *res, t_mlx	*vars);

//il faut zoomer avant de faire iso et center
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

/*applies a translation to the drawing*/
void	ft_trans(t_map *maps, t_mlx *vars)
{
	int	i;

	i = 0;
	while (i < vars->max)
	{
		maps->x[i] += vars->trans_x;
		maps->y[i] += vars->trans_y;
		i++;
	}
	vars->center_x += vars->trans_x;
	vars->center_y += vars->trans_y;
}

/*centers the maps*/
void	ft_center(t_map *maps, t_mlx *vars)
{
	int		i;
	int		x_margin;
	int		y_margin;
	t_point	*xtrem;

	xtrem = ft_extrem_values(maps, vars);
	x_margin = (WIDTH - xtrem->max_x + xtrem->min_x) / 2 - xtrem->min_x;
	y_margin = (HEIGHT - xtrem->max_y + xtrem->min_y) / 2 - xtrem->min_y;
	free (xtrem);
	vars->margin_x = x_margin;
	vars->margin_y = y_margin;
	i = 0;
	while (i < vars->max)
	{
		maps->x[i] += x_margin;
		maps->y[i] += y_margin;
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

void	ft_altitude(t_map *res, t_mlx *vars)
{
	int	i;

	i = 0;
	while (i < vars->max)
	{
		if (res->z[i] != 0)
			res->z[i] = res->z[i] * vars->altitude;
		i++;
	}
}
