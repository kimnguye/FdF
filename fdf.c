/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:40:50 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/23 13:16:04 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	*vars;

	if (fdf_parsing(argc, argv))
		return (1);
	vars = fdf_init_vars();
	if (!vars)
		return (1);
	fdf_init_map(vars, argv);
	if (vars->map == NULL)
		return (1);
	ft_printf("Memory allocation : SUCCES\n");
	fd = open(argv[1], O_RDONLY);
	fdf_save_map(fd, vars);
	close (fd);
	ft_printf("Sauvegarde de la carte: SUCCES\n");
	vars->res = ft_dup_map(vars->map, vars);
	if (!vars->res)
		return (ft_close(vars, 5), 1);
	ft_initial_view(vars);
	mlx_hook(vars->win, KEYPRESS_EVENT, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, BUTTONPRESS_EVENT, 1L << 2, mouse_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close_all, vars);
	mlx_loop(vars->mlx);
	return (0);
}
