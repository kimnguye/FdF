/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:54:52 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:42 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_i(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	return (ft_nbr_len(n));
}
