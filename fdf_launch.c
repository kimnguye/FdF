/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:15 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/28 12:10:12 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define LAUNCH_IMG_PATH "xpm/Welcome-to-FdF-42-1080.xpm"
#define BYE_IMG_PATH "xpm/Goodbye-FdF-42-1080.xpm"

void	ft_launch_hi(t_mlx *vars)
{
	vars->img_hi = mlx_xpm_file_to_image
		(vars->mlx, LAUNCH_IMG_PATH, &vars->w_hi, &vars->h_hi);
	if (vars->img_hi)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_hi, 0, 0);
}
