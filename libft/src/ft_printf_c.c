/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:39:46 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:47 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_c(va_list args)
{
	char	x;

	x = va_arg(args, int);
	write(1, &x, 1);
	return (1);
}
