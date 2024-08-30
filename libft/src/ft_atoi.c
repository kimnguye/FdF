/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:53:12 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:01 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * nb);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		printf("atoi: %i\n", atoi(av[1]));
// 		printf("ft_atoi: %i\n", ft_atoi(av[1]));
// 	}
// 	return (0);
// }
