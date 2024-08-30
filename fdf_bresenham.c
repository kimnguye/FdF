/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:53:47 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 18:24:09 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//mlx_pixel_put(param->mlx, param->win, map->x[a], y, ft_color(map, a, b, ab));

void	ft_segment_vertical(t_map *map, int a, int b, t_mlx *param, t_slope *ab)
{
	int	y;
	int	y_max;

	y = map->y[a];
	y_max = map->y[b];
	while (y <= y_max)
	{
		if (map->x[a] >= 0 && map->x[a] <= WIDTH && y >= 0 && y <= HEIGHT)
			ft_put_pixel_to_img(param, map->x[a], y, ft_color(map, a, b, ab));
		y++;
	}
}
//mlx_pixel_put(vars->mlx, vars->win, ab->i, ab->j, ft_color(map, a, b, ab));

void	ft_segment_q1(t_map *map, int a, int b, t_mlx *vars, t_slope *ab)
{
	ab->p = 2 * ab->dy - ab->dx;
	while (ab->dx >= ab->dy && ab->i <= map->x[b])
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p += 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j++;
			ab->p -= 2 * ab->dx;
		}
		ab->i++;
	}
	while (ab->dy > ab->dx && ab->j <= map->y[b])
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p += 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i++;
			ab->p -= 2 * ab->dy;
		}
		ab->j++;
	}
}

void	ft_segment_q2(t_map *map, int a, int b, t_mlx *vars, t_slope *ab)
{
	ab->p = 2 * ab->dx - ab->dy;
	while (ab->i >= map->x[b] && (abs(ab->dy) <= abs(ab->dx)))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p += 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j++;
			ab->p += 2 * ab->dx;
		}
		ab->i--;
	}
	while (ab->j <= map->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p -= 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i--;
			ab->p -= 2 * ab->dy;
		}
		ab->j++;
	}
}

void	ft_segment_q3(t_map *map, int a, int b, t_mlx *vars, t_slope *ab)
{
	ab->p = 2 * ab->dx - ab->dy;
	while (ab->i >= map->x[b] && abs(ab->dy) <= abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p -= 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j--;
			ab->p += 2 * ab->dx;
		}
		ab->i--;
	}
	while (ab->j >= map->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p -= 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i--;
			ab->p += 2 * ab->dy;
		}
		ab->j--;
	}
}

void	ft_segment_q4(t_map *map, int a, int b, t_mlx *vars, t_slope *ab)
{
	ab->p = 2 * ab->dy - ab->dx;
	while (ab->i <= map->x[b] && abs(ab->dy) <= abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p -= 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j--;
			ab->p -= 2 * ab->dx;
		}
		ab->i++;
	}
	while (ab->j >= map->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(vars, ab->i, ab->j, ft_color(map, a, b, ab));
		ab->p += 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i++;
			ab->p += 2 * ab->dy;
		}
		ab->j--;
	}
}
