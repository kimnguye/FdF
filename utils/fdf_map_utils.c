/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:12:46 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 17:03:35 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_copy_map(t_map *map, t_map *res, t_mlx *vars);
t_map	*ft_dup_map(t_map *map, t_mlx *vars);
void	ft_free_map(t_map *map, t_mlx *vars);
t_map	*ft_malloc_map(t_mlx *vars);

/*copy the values of map into res*/
void	ft_copy_map(t_map *map, t_map *res, t_mlx *vars)
{
	int		i;
	int		nb;

	i = 0;
	nb = vars->max_x * vars->max_y;
	while (i < nb)
	{
		res->x[i] = map->x[i];
		res->y[i] = map->y[i];
		res->z[i] = map->z[i];
		res->color[i] = map->color[i];
		i++;
	}
}

/*returns a dup of map*/
t_map	*ft_dup_map(t_map *map, t_mlx *vars)
{
	t_map	*dup;
	int		i;
	int		nb;

	dup = ft_malloc_map(vars);
	if (!dup)
		return (NULL);
	i = 0;
	nb = vars->max_x * vars->max_y;
	while (i < nb)
	{
		dup->x[i] = map->x[i];
		dup->y[i] = map->y[i];
		dup->z[i] = map->z[i];
		dup->color[i] = map->color[i];
		i++;
	}
	return (dup);
}

/*free map*/
void	ft_free_map(t_map *map, t_mlx *vars)
{
	free(map->x);
	free(map->y);
	free(map->z);
	free(map->color);
	free(map);
}

t_map	*ft_malloc_map(t_mlx *vars)
{
	t_map	*map;
	int		nb;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	nb = vars->max_x * vars->max_y;
	map->x = malloc(sizeof(int) * nb);
	if (map->x == NULL)
		return (free(map), NULL);
	map->y = malloc(sizeof(int) * nb);
	if (map->y == NULL)
		return (free(map->x), free(map), NULL);
	map->z = malloc(sizeof(int) * nb);
	if (map->z == NULL)
		return (free(map->x), free(map->y), free(map), NULL);
	map->color = malloc(sizeof(int) * nb);
	if (map->color == NULL)
		return (free(map->x), free(map->y), free(map->z), free(map), NULL);
	return (map);
}
