/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:10:16 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:37 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
