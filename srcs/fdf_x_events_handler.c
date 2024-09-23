/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:23 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:07:15 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_hook(int button, int x, int y, t_mlx *param);
int		key_hook(int key, t_mlx *param);
int		ft_rot_handler(int key, t_mlx *param);
void	ft_translation_handler(int key, t_mlx *vars);

/*mouse events hendler; (x, y) are the coordinates of the click in the window,
and button tells you which mouse button was pressed*/
int	mouse_hook(int button, int x, int y, t_mlx *param)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		param->zoom *= ZOOM_PLUS;
	else if (button == SCROLL_DOWN)
		param->zoom *= ZOOM_MINUS;
	else if (button == RIGHT_CLICK)
			param->rot_iso -= ANGLE_ROT;
	else if (button == LEFT_CLICK)
			param->rot_iso += ANGLE_ROT;
	ft_calc_view(param);
	return (0);
}

//fct called by mlx_key_hook
int	key_hook(int key, t_mlx *param)
{
	if (key == ESC || key == KEY_Q || key == KEY_Q_MAC)
		ft_close(param, CLOSE_ALL);
	else if (key == ENTER)
		ft_iso_view(param);
	else if (key == SPACE)
		ft_above_view(param);
	else if ((key >= LEFT && key <= BOTTOM) || (key >= NUM_7 && key <= NUM_1))
	{
		ft_translation_handler(key, param);
		ft_rot_handler(key, param);
		if (key == NUM_8)
			param->altitude *= ZOOM_PLUS;
		else if (key == NUM_2)
			param->altitude *= ZOOM_MINUS;
		ft_calc_view(param);
	}
	else
		ft_printf("la touche %i a été utilisée\n", key);
	return (0);
}

/*returns rotation code*/
int	ft_rot_handler(int key, t_mlx *param)
{
	if (key == NUM_7)
		param->rot_z -= ANGLE_ROT;
	else if (key == NUM_9)
		param->rot_z += ANGLE_ROT;
	else if (key == NUM_4)
		param->rot_y += ANGLE_ROT;
	else if (key == NUM_6)
		param->rot_y -= ANGLE_ROT;
	else if (key == NUM_1)
		param->rot_x -= ANGLE_ROT;
	else if (key == NUM_3)
		param->rot_x += ANGLE_ROT;
	else
		return (0);
	return (ROT_CODE);
}

void	ft_translation_handler(int key, t_mlx *vars)
{
	int	speed;

	speed = 1 * TRANS;
	if (vars->zoom >= ZOOM_INIT * 3)
		speed = 2 * TRANS;
	if (key == LEFT)
	{
		vars->trans_x -= speed;
		vars->center_x -= speed;
	}
	else if (key == RIGHT)
	{
		vars->trans_x += speed;
		vars->center_x += speed;
	}
	else if (key == BOTTOM)
	{
		vars->trans_y += speed;
		vars->center_y += speed;
	}
	else if (key == TOP)
	{
		vars->trans_y -= speed;
		vars->center_y -= speed;
	}
}
