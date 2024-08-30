/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transfo_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:23:36 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/28 16:58:00 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate(t_point ***res, t_mlx *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->max_y)
	{
		i = 0;
		while (i < vars->max_x)
		{
			ft_move_to_0(res[j][i], vars);
			rotate_x(res[j][i], vars);
			rotate_y(res[j][i], vars);
			rotate_z(res[j][i], vars);
			ft_move_to_center(res[j][i], vars);
			i++;
		}
		j++;
	}
}

void	rotate_z(t_point *a, t_mlx *vars)
{
	int		tmp;
	float	rad;

	rad = de_to_rad(vars->rot_z);
	tmp = a->x;
	a->x = tmp * cos(rad) - a->y * sin(rad);
	a->y = tmp * sin(rad) + a->y * cos(rad);
}

void	rotate_y(t_point *a, t_mlx *vars)
{
	int		tmp;
	float	rad;

	rad = de_to_rad(vars->rot_y);
	tmp = a->x;
	a->x = tmp * cos(rad) + a->z * sin(rad);
	a->z = a->z * cos(rad) - tmp * sin(rad);
}

void	rotate_x(t_point *a, t_mlx *vars)
{
	int		tmp;
	float	rad;

	rad = de_to_rad(vars->rot_x);
	tmp = a->y;
	a->y = tmp * cos(rad) - a->z * sin(rad);
	a->z = tmp * sin(rad) + a->z * cos(rad);
}
