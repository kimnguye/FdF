/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:18:37 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:08:08 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*ft_point_new(int min_x, int max_x, int min_y, int max_y);
t_point	*ft_extrem_values(t_map *maps, t_mlx *vars);

/*returns a ptr on the point (x, y, z)*/
t_point	*ft_point_new(int min_x, int max_x, int min_y, int max_y)
{
	t_point	*new;

	new = malloc (sizeof(t_point));
	if (!new)
		return (NULL);
	new->min_x = min_x;
	new->max_x = max_x;
	new->min_y = min_y;
	new->max_y = max_y;
	return (new);
}

/*returns the extreme values : x_min, y_min, x_max and y_max*/
t_point	*ft_extrem_values(t_map *maps, t_mlx *vars)
{
	int		i;
	t_point	*max_val;

	max_val = ft_point_new(maps->x[0], maps->x[0],
			maps->y[0], maps->y[0]);
	i = -1;
	while (++i < vars->max)
	{
		if (maps->x[i] > max_val->max_x)
			max_val->max_x = maps->x[i];
		if (maps->x[i] < max_val->min_x)
			max_val->min_x = maps->x[i];
		if (maps->y[i] > max_val->max_y)
			max_val->max_y = maps->y[i];
		if (maps->y[i] < max_val->min_x)
			max_val->min_x = maps->y[i];
	}
	return (max_val);
}
