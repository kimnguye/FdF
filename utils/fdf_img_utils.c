/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:31:44 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 18:22:10 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*put pixel to img*/
void	ft_put_pixel_to_img(t_mlx *vars, int x, int y, int color)
{
	int	pixel;

	pixel = (y * vars->line_size) + (x * (vars->pixel_bits / 8));
	vars->img_data[pixel] = color & 0xFF;
	vars->img_data[pixel + 1] = (color >> 8) & 0xFF;
	vars->img_data[pixel + 2] = (color >> 16) & 0xFF;
}

int	ft_color(t_map *maps, int a, int b, t_slope *ab)
{
	int		color_r;
	int		color_g;
	int		color_b;
	double	frac;

	frac = ft_dist_percent(a, b, ab);
	color_r = frac * ((maps->color[b] >> 16) & 0xFF)
		+ (1 - frac) * ((maps->color[a] >> 16) & 0xFF);
	color_g = frac * ((maps->color[b] >> 8) & 0xFF)
		+ (1 - frac) * ((maps->color[a] >> 8) & 0xFF);
	color_b = frac * (maps->color[b] & 0xFF) + (1 - frac) * (maps->color[a] & 0xFF);
	return ((color_r << 16) | (color_g << 8) | color_b);
}
