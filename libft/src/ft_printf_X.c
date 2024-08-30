/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:07:21 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:30 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_x_cap(va_list args)
{
	int		n;
	char	*base;

	base = "0123456789ABCDEF";
	n = va_arg(args, int);
	if (n < 0)
		return (ft_put_neglld_base(n, base));
	return (ft_put_poslld_base(n, base));
}
