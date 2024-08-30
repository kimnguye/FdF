/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:18:37 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 17:52:37 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*ft_point_new(int min_x, int max_x, int min_y, int max_y);

/*returns a ptr on the point (x, y, z)*/
t_point	*ft_point_new(int min_x, int max_x, int min_y, int max_y)
{
	t_point	*new;

	new = malloc (sizeof(t_point));
	if (!new)
		return (NULL);
	new->min_x = min_x;
	new->max_x = max_x;
	new->min_y = min_y;
	new->max_y = max_y;
	return (new);
}
