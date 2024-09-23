/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:43:55 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 14:29:50 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
//# include "/home/kimnguye/sgoinfre/minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include "fdf_define.h"
# include "fdf_struct.h"

/* FUNCTIONS */

//launch
void	ft_launch_hi(t_mlx *vars);

//parsing and errors handler
int	fdf_parsing(int argc, char **argv);
int	ft_close(t_mlx *param, unsigned int code);
int	ft_close_all(t_mlx *param);

//initialize variables
t_mlx	*fdf_init_vars(void);
int		ft_init_max(int fd, t_mlx *vars);
void	fdf_init_map(t_mlx *vars, char **argv);
void	ft_init_param_view(t_mlx *vars);

//save the map
void	ft_save_point(char *data, t_mlx *vars, int i, int j);
void	fdf_save_map(int fd, t_mlx *vars);

//transfo
void	ft_center_and_trans(t_map *maps, t_mlx *vars);
void	ft_transfo(t_map *map, t_map *res, t_mlx *vars);
void	ft_margin(t_map *maps, t_mlx *vars);
void	ft_zoom(t_map *map, t_map *res, t_mlx *vars, float zoom);
void	ft_iso(t_map *maps, int degree, t_mlx *vars);
void	ft_rotate(t_map *res, t_mlx *vars);

// drawing
void	ft_draw_map(t_mlx *vars);
int		ft_color(t_mlx *vars, int a, int b, t_slope *ab);
void	ft_draw_line(int x, int y, t_mlx *param);
void	ft_erase_map(t_mlx *vars);

//different map views
void	ft_initial_view(t_mlx *param);
void	ft_iso_view(t_mlx *param);
void	ft_above_view(t_mlx *param);
void	ft_calc_view(t_mlx *param);

//img utils
void	ft_pixel_to_img(t_mlx *vars, int x, int y, int color);
int		isin_img(int x, int y);

//events handler
int		mouse_hook(int button, int x, int y, t_mlx *param);
int		key_hook(int key, t_mlx *param);
int		ft_rot_handler(int key, t_mlx *param);
void	ft_translation_handler(int key, t_mlx *vars);

//fdf utils
t_mlx	*fdf_init_vars(void);
void	ft_init_param_view(t_mlx *vars);

//map utils
void	ft_copy_map(t_map *map, t_map *res, t_mlx *vars);
t_map	*ft_dup_map(t_map *map, t_mlx *vars);
void	ft_free_map(t_map *map);
t_map	*ft_malloc_map(t_mlx *vars);

//point utils
t_point	*ft_point_new(int min_x, int max_x, int min_y, int max_y);
t_point	*ft_extrem_values(t_map *maps, t_mlx *vars);

//bresenham
void	ft_segment(int a, int b, t_mlx *vars);
void	ft_segment_vertical(int a, int b, t_mlx *param, t_slope *ab);
void	ft_segment_q1(int a, int b, t_mlx *vars, t_slope *ab);
void	ft_segment_q2(int a, int b, t_mlx *vars, t_slope *ab);
void	ft_segment_q3(int a, int b, t_mlx *vars, t_slope *ab);
void	ft_segment_q4(int a, int b, t_mlx *vars, t_slope *ab);

//calc utils
double	ft_dist(int x1, int y1, int x2, int y2);
double	ft_dist_percent(t_map *maps, int a, int b, t_slope *ab);
void	ft_move_to_0(int *x, int *y, t_mlx *vars);
void	ft_move_to_center(int *x, int *y, t_mlx *vars);
float	de_to_rad(int de);

#endif
