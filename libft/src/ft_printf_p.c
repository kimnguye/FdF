/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:39:50 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:40 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define VAL_NIL "(nil)"

int	ft_printf_p(va_list args)
{
	unsigned long long	adr;
	char				*base;
	char				*prefixe;

	prefixe = "0x";
	base = "0123456789abcdef";
	adr = (unsigned long long) va_arg(args, void *);
	if (!adr)
	{
		ft_putstr_fd(VAL_NIL, 1);
		return (ft_strlen(VAL_NIL));
	}
	write (1, prefixe, ft_strlen(prefixe));
	return (ft_put_poslld_base(adr, base) + ft_strlen(prefixe));
}
