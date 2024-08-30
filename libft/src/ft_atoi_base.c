/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:54:59 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/18 12:57:50 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:08:31 by kimnguye          #+#    #+#             */
/*   Updated: 2024/03/30 14:42:32 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	is_in(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

/*converts an asci string into an int in the indicated base*/
int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	sign;
	int	nb;

	nb = 0;
	sign = 0;
	len = checkbase(base);
	if (len < 2)
		return (0);
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (is_in(*str, base) != -1)
	{
		nb = nb * len + is_in(*str, base);
		str++;
	}
	if (sign % 2 && nb != 0)
		return (-nb);
	return (nb);
}
