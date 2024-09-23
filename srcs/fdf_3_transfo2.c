/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transfo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:23:36 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:11:15 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso(t_map *maps, int degree, t_mlx *vars);
void	ft_rotate(t_map *res, t_mlx *vars);

/*rotate x (step 0), y (step 1) and z (step 2)*/
void	ft_rotate(t_map *res, t_mlx *vars)
{
	int		i;
	int		tmp[3];
	float	rad[3];

	rad[0] = de_to_rad(vars->rot_x);
	rad[1] = de_to_rad(vars->rot_y);
	rad[2] = de_to_rad(vars->rot_z);
	i = 0;
	while (i < vars->max)
	{
		ft_move_to_0(&res->x[i], &res->y[i], vars);
		tmp[0] = res->y[i];
		res->y[i] = tmp[0] * cos(rad[0]) - res->z[i] * sin(rad[0]);
		res->z[i] = tmp[0] * sin(rad[0]) + res->z[i] * cos(rad[0]);
		tmp[1] = res->x[i];
		res->x[i] = tmp[1] * cos(rad[1]) + res->z[i] * sin(rad[1]);
		res->z[i] = res->z[i] * cos(rad[1]) - tmp[1] * sin(rad[1]);
		tmp[2] = res->x[i];
		res->x[i] = tmp[2] * cos(rad[2]) - res->y[i] * sin(rad[2]);
		res->y[i] = tmp[2] * sin(rad[2]) + res->y[i] * cos(rad[2]);
		ft_move_to_center(&res->x[i], &res->y[i], vars);
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
