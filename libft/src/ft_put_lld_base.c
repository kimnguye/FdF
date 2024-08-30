/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lld_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:05:10 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 15:51:02 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_poslld_base(unsigned long long nbr, char *base)
{
	unsigned int	ctr;
	unsigned int	siz_base;

	ctr = 1;
	siz_base = ft_strlen(base);
	if (nbr > siz_base - 1)
		ctr += ft_put_poslld_base(nbr / siz_base, base);
	write (1, &base[nbr % siz_base], 1);
	return (ctr);
}

int	ft_put_neglld_base(long long nbr, char *base)
{
	int	siz_base;

	siz_base = ft_strlen(base);
	nbr = ft_pow(siz_base, 8) + nbr;
	return (ft_put_poslld_base(nbr, base));
}
