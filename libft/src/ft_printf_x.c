/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:18:01 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:33 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_x(va_list args)
{
	int		n;
	char	*base;

	base = "0123456789abcdef";
	n = va_arg(args, int);
	if (n < 0)
		return (ft_put_neglld_base(n, base));
	return (ft_put_poslld_base(n, base));
}
