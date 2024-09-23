/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_save_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:33:20 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:17:55 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_init_max(int fd, t_mlx *vars);
void	fdf_init_map(t_mlx *vars, char **argv);
void	ft_save_point(char *data, t_mlx *vars, int i, int j);
void	fdf_save_map(int fd, t_mlx *vars);

/*read the map and retrieve the data*/
void	fdf_save_map(int fd, t_mlx *vars)
{
	char	*line;
	char	**data;
	int		i;
	int		j;

	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		data = ft_split(line, ' ');
		i = -1;
		while (++i < vars->max_x)
		{
			vars->map->x[i + j] = i;
			vars->map->y[i + j] = j / vars->max_x;
			ft_save_point(data[i], vars, i, j);
		}
		free(line);
		ft_free_split(data);
		line = get_next_line(fd);
		j += i;
	}
}

void	ft_save_point(char *data, t_mlx *vars, int i, int j)
{
	char	**split_color;

	if (ft_countsplits(data, ',') == 1)
	{
		vars->map->z[i + j] = ft_atoi(data);
		vars->map->color[i + j] = DEFAULT_COLOR;
	}
	else
	{
		split_color = ft_split(data, ',');
		vars->map->z[i + j] = ft_atoi(split_color[0]);
		vars->map->color[i + j] = ft_atoi_base
			(ft_str_ucase(&split_color[1][2]), BASE_HEXA);
		ft_free_split(split_color);
	}
}
