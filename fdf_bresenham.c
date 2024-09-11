/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:53:47 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/12 00:03:09 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_segment_vertical(int a, int b, t_mlx *param, t_slope *ab)
{
	int	y;
	int	y_max;

	if (param->res->y[a] <= param->res->y[b])
	{
		y = param->res->y[a];
		y_max = param->res->y[b];
	}
	else
	{
		y = param->res->y[b];
		y_max = param->res->y[a];
	}
	while (y <= y_max)
	{
		if (isin_img(param->res->x[a], y))
			ft_put_pixel_to_img(param, param->res->x[a], y,
			ft_color(param->res, a, b, ab));
		y++;
	}
}

void	ft_segment_q1(int a, int b, t_mlx *param, t_slope *ab)
{
	ab->p = 2 * ab->dy - ab->dx;
	while (ab->dx >= ab->dy && ab->i <= param->res->x[b])
	{
		if (isin_img(ab->i, ab->j))
			ft_put_pixel_to_img(param, ab->i, ab->j,
				ft_color(param->res, a, b, ab));
		ab->p += 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j++;
			ab->p -= 2 * ab->dx;
		}
		ab->i++;
	}
	while (ab->dy > ab->dx && ab->j <= param->res->y[b])
	{
		if (isin_img(ab->i, ab->j))
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p += 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i++;
			ab->p -= 2 * ab->dy;
		}
		ab->j++;
	}
}

void	ft_segment_q2(int a, int b, t_mlx *param, t_slope *ab)
{
	ab->p = 2 * ab->dx - ab->dy;
	while (ab->i >= param->res->x[b] && (abs(ab->dy) <= abs(ab->dx)))
	{
		if (isin_img(ab->i, ab->j))
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p += 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j++;
			ab->p += 2 * ab->dx;
		}
		ab->i--;
	}
	while (ab->j <= param->res->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (isin_img(ab->i, ab->j))
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p -= 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i--;
			ab->p -= 2 * ab->dy;
		}
		ab->j++;
	}
}

void	ft_segment_q3(int a, int b, t_mlx *param, t_slope *ab)
{
	ab->p = 2 * ab->dx - ab->dy;
	while (ab->i >= param->res->x[b] && abs(ab->dy) <= abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p -= 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j--;
			ab->p += 2 * ab->dx;
		}
		ab->i--;
	}
	while (ab->j >= param->res->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p -= 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i--;
			ab->p += 2 * ab->dy;
		}
		ab->j--;
	}
}

void	ft_segment_q4(int a, int b, t_mlx *param, t_slope *ab)
{
	ab->p = 2 * ab->dy - ab->dx;
	while (ab->i <= param->res->x[b] && abs(ab->dy) <= abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p -= 2 * ab->dy;
		if (ab->p >= 0)
		{
			ab->j--;
			ab->p -= 2 * ab->dx;
		}
		ab->i++;
	}
	while (ab->j >= param->res->y[b] && abs(ab->dy) > abs(ab->dx))
	{
		if (ab->i >= 0 && ab->i <= WIDTH && ab->j >= 0 && ab->j <= HEIGHT)
			ft_put_pixel_to_img(param, ab->i, ab->j, ft_color(param->res, a, b, ab));
		ab->p += 2 * ab->dx;
		if (ab->p >= 0)
		{
			ab->i++;
			ab->p += 2 * ab->dy;
		}
		ab->j--;
	}
}
