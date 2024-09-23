/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:51:58 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:15:31 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_parsing(int argc, char **argv);
int	ft_close(t_mlx *param, unsigned int code);
int	ft_close_all(t_mlx *param);

/*returns 1 on error :
file does not exist, too many arguments, etc.*/
int	fdf_parsing(int argc, char **argv)
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
		ft_free_map(param->res);
	if (code >= 4)
		ft_free_map(param->map);
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
