/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:52:44 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:23 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	conversion_reader(const char c, va_list args)
{
	int	ctr;

	ctr = 0;
	if (c == 'c')
		ctr += ft_printf_c(args);
	else if (c == 'd')
		ctr += ft_printf_d(args);
	else if (c == 'i')
		ctr += ft_printf_i(args);
	else if (c == 'p')
		ctr += ft_printf_p(args);
	else if (c == 's')
		ctr += ft_printf_s(args);
	else if (c == 'u')
		ctr += ft_printf_u(args);
	else if (c == 'x')
		ctr += ft_printf_x(args);
	else if (c == 'X')
		ctr += ft_printf_x_cap(args);
	else if (c == '%')
	{
		write(1, "%", 1);
		ctr += 1;
	}
	return (ctr);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	const char	*ptr;
	int			ctr;

	if (!s)
		return (-1);
	ctr = 0;
	ptr = s;
	va_start(args, s);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ctr += conversion_reader(ptr[1], args);
			ptr += 2;
		}
		else
		{
			write(1, ptr, 1);
			ctr++;
			ptr++;
		}
	}
	va_end(args);
	return (ctr);
}
