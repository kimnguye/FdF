/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:29:23 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/11 16:14:32 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*mouse events hendler; (x, y) are the coordinates of the click in the window,
and button tells you which mouse button was pressed*/
int	mouse_hook(int button, int x, int y, t_mlx *param)
{
	if (button == SCROLL_CLICK)
		ft_draw_line(x, y, param);
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			param->zoom *= ZOOM_PLUS;
		else
			param->zoom *= ZOOM_MINUS;
		ft_calc_view(param, 0);
	}
	else if (button == LEFT_CLICK || button == RIGHT_CLICK)
	{
		if (button == RIGHT_CLICK)
			param->rot_iso -= ANGLE_ROT;
		else
			param->rot_iso += ANGLE_ROT;
		ft_calc_view(param, ROT_CODE);
	}
	return (0);
}

//fct called by mlx_key_hook
int	key_hook(int key, t_mlx *param)
{
	int	code_calc;

	code_calc = 0;
	if (key == ESC || key == KEY_Q || key == KEY_Q_MAC)
		ft_close(param, CLOSE_ALL);
	else if (key == ENTER)
		ft_iso_view(param);
	else if (key == SPACE)
		ft_above_view(param);
	else if ((key >= LEFT && key <= BOTTOM) || (key >= NUM_7 && key <= NUM_1))
	{
		ft_zoom_handler(key, param);
		code_calc = ft_rot_handler(key, param);
		if (key == NUM_8)
			param->altitude *= ZOOM_PLUS;
		else if (key == NUM_2)
			param->altitude *= ZOOM_MINUS;
		ft_calc_view(param, code_calc);
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

void	ft_zoom_handler(int key, t_mlx *param)
{
	if (key == LEFT)
		param->trans_x -= TRANS * param->zoom;
	else if (key == RIGHT)
		param->trans_x += TRANS * param->zoom;
	else if (key == BOTTOM)
		param->trans_y += TRANS * param->zoom;
	else if (key == TOP)
		param->trans_y -= TRANS * param->zoom;
}
