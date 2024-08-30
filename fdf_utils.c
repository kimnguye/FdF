/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:51:58 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 10:25:09 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* initialize the parameters view (zoom, translation, center)*/
void	ft_init_param_view(t_mlx *vars)
{
	vars->zoom = ZOOM_INIT;
	vars->altitude = 1;
	vars->trans_x = 0;
	vars->trans_y = 0;
	vars->margin_x = 0;
	vars->margin_x = 0;
	vars->rot_iso = ANGLE_INIT;
	vars->rot_x = 0;
	vars->rot_y = 0;
	vars->rot_z = 0;
	vars->center_x = WIDTH / 2;
	vars->center_y = HEIGHT / 2;
}

/*returns 1 on error :
file does not exist, too many arguments, etc.*/
int	ft_fdf_errors(int argc, char **argv)
{
	int		n;

	if (argc > 2)
	{
		ft_printf("Please check your arguments! Only 1 argument is expected!\n");
		return (1);
	}
	else if (argc < 2)
	{
		ft_printf("Please check your arguments! One argument is expected!\n");
		return (1);
	}
	n = ft_strlen(argv[1]);
	if (ft_strncmp(".fdf", &argv[1][n - 4], 4))
		return (ft_printf("Wrong file format: a fdf is expected!\n"), 1);
	n = open(argv[1], O_RDONLY);
	if (n == -1)
		return (ft_printf(
				"Check your arguments :your file does not exist!\n"), 1);
	close(n);
	return (0);
}

/*closes the program and uses a closing code*/
int	ft_close(t_mlx *param, unsigned int code)
{
	if (code >= 5)
		ft_free_map(param->res, param);
	if (code >= 4)
		ft_free_map(param->map, param);
	if (code >= 3)
		mlx_destroy_image(param->mlx, param->img_hi);
	if (code >= 2)
		mlx_destroy_image(param->mlx, param->img);
	if (code >= 1)
		mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free(param);
	if (code <= 5)
		ft_printf(" (error code: %i)\n", code);
	exit(EXIT_SUCCESS);
	return (0);
}

/*closes the program and free everything*/
int	ft_close_all(t_mlx *param)
{
	return (ft_close(param, CLOSE_ALL));
}

/*initialize mlx_ptr, win_ptr, img_ptr, img_data, img_hi*/
t_mlx	*ft_init_vars(void)
{
	t_mlx	*vars;

	vars = malloc (sizeof(t_mlx));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free(vars), NULL);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "kimnguye - FdF 42");
	if (!vars->win)
		return (ft_close(vars, 0), NULL);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		return (ft_close(vars, 1), NULL);
	vars->img_data = mlx_get_data_addr
		(vars->img, &vars->pixel_bits, &vars->line_size, &vars->endian);
	if (!vars->img_data)
		return (ft_close(vars, 2), NULL);
	ft_launch_hi(vars);
	if (!vars->img_hi)
		return (ft_close(vars, 3), NULL);
	return (vars);
}
