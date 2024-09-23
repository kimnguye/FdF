/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:28:48 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:08:01 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_dist(int x1, int y1, int x2, int y2);
double	ft_dist_percent(t_map *maps, int a, int b, t_slope *ab);
float	de_to_rad(int de);
void	ft_move_to_0(int *x, int *y, t_mlx *vars);
void	ft_move_to_center(int *x, int *y, t_mlx *vars);

void	ft_move_to_0(int *x, int *y, t_mlx *vars)
{
	*x -= vars->center_x;
	*y -= vars->center_y;
}

void	ft_move_to_center(int *x, int *y, t_mlx *vars)
{
	*x += vars->center_x;
	*y += vars->center_y;
}
/*returns dist runs / dist total*/
double	ft_dist_percent(t_map *maps, int a, int b, t_slope *ab)
{
	double	dist_total;
	double	dist_a;
	double	dist_percent;

	dist_total = ft_dist(maps->x[a], maps->y[a], maps->x[b], maps->y[b]);
	dist_a = ft_dist(maps->x[a], maps->y[a], ab->i, ab->j);
	dist_percent = dist_a / dist_total;
	return (dist_percent);
}

/*converts degrees into radians*/
float	de_to_rad(int de)
{
	float	rad;

	rad = de * M_PI / 180;
	return (rad);
}

/*returns the distance between A(x1, y1) and B(x2, y2)*/
double	ft_dist(int x1, int y1, int x2, int y2)
{
	double	dist;

	dist = round(sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2)));
	return (dist);
}
