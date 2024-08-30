/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:28:48 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/27 09:43:58 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	ft_dist(int x1, int y1, int x2, int y2);
double	ft_dist_percent(t_point *a, t_point *b, t_slope *ab);
void	ft_move_to_0(t_point *a, t_mlx *vars);
void	ft_move_to_center(t_point *a, t_mlx *vars);
float	de_to_rad(int de);

/*returns dist runs / dist total*/
double	ft_dist_percent(t_point *a, t_point *b, t_slope *ab)
{
	double	dist_total;
	double	dist_a;
	double	dist_percent;

	dist_total = ft_dist(a->x, a->y, b->x, b->y);
	dist_a = ft_dist(a->x, a->y, ab->i, ab->j);
	dist_percent = dist_a / dist_total;
	return (dist_percent);
}

void	ft_move_to_0(t_point *a, t_mlx *vars)
{
	a->x -= vars->center_x;
	a->y -= vars->center_y;
}

void	ft_move_to_center(t_point *a, t_mlx *vars)
{
	a->x += vars->center_x;
	a->y += vars->center_y;
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
