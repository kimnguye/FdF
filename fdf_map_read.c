/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:33:20 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/11 17:01:26 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*counts the nb of points in the map (max_x and max_y) fd
returns 0 when success
returns -1 if gnl failed
returns -2 if the map is not rectangular*/
int	ft_init_max(int fd, t_mlx *vars)
{
	char	*gnl;
	int		line_x;

	vars->max_y = 0;
	gnl = get_next_line(fd);
	if (gnl == NULL)
		return (ft_printf("GNL failed\n"), -1);
	vars->max_x = ft_countsplits(gnl, ' ');
	while (gnl)
	{
		vars->max_y++;
		line_x = ft_countsplits(gnl, ' ');
		if (line_x < vars->max_x)
			return (close(fd), get_next_line(fd), free(gnl),
				ft_printf("Memory allocation: FAILED\n"),
				ft_printf("A rectangular map is expected!"), -2);
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	vars->max = vars->max_x * vars->max_y;
	return (0);
}

/*returns a mallocated map
close the program on errors*/
void	ft_init_map(t_mlx *vars, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_close(vars, 3), (void)0);
	if (ft_init_max(fd, vars) < 0)
		return (ft_close(vars, 3), (void)0);
	vars->map = ft_malloc_map(vars);
	if (vars->map == NULL)
		return (ft_close(vars, 4), (void)0);
}

/*read the map and retrieve the data*/
void	ft_save_map(int fd, t_mlx *vars)
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
