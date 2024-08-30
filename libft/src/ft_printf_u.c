/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:02:29 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:35 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_unsigned_int(unsigned int n)
{
	if (n > 9)
	{
		ft_put_unsigned_int(n / 10);
		ft_put_unsigned_int(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
	}
}

int	ft_unsigned_int_len(unsigned int nbr)
{
	int		siz;

	siz = 0;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		siz++;
	}
	return (siz + 1);
}

int	ft_printf_u(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_put_unsigned_int(n);
	return (ft_unsigned_int_len(n));
}
