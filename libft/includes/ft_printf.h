/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:46:26 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:51:22 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

int		ft_printf(const char *s, ...);
int		ft_printf_c(va_list args);
int		ft_printf_d(va_list args);
int		ft_printf_i(va_list args);
int		ft_printf_p(va_list args);
int		ft_printf_s(va_list args);
int		ft_printf_u(va_list args);
int		ft_printf_x(va_list args);
int		ft_printf_x_cap(va_list args);

int		ft_unsigned_int_len(unsigned int nbr);
void	ft_put_unsigned_int(unsigned int n);
int		ft_put_poslld_base(unsigned long long nbr, char *base);
int		ft_put_neglld_base(long long nbr, char *base);
long	ft_pow(int x, unsigned int p);
#endif
