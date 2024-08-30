/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_fdf_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:37:03 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 17:42:46 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FDF_STRUCT_H
# define HEADER_FDF_STRUCT_H

/* STRUCTURES */

typedef struct s_map {
	int	*x;
	int	*y;
	int	*z;
	int	*color;
}	t_map;

typedef struct s_point {
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
}	t_point;

typedef struct s_slope {
	int	dx;
	int	dy;
	int	p;
	int	i;
	int	j;
}	t_slope;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_hi;
	char	*img_data;
	int		w_hi;
	int		h_hi;
	int		pixel_bits;
	int		line_size;
	int		endian;
	int		max_y;
	int		max_x;
	int		max;
	t_map	*map;
	t_map	*res;
	int		margin_x;
	int		margin_y;
	int		center_x;
	int		center_y;
	int		trans_x;
	int		trans_y;
	float	zoom;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	int		rot_iso;
	float	altitude;
}	t_mlx;

#endif
