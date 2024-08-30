/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:55:13 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:27 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (16384);
	return (0);
}

// int	main(void)
// {
// 	printf("%i : %i\n", isprint(127), ft_isprint(127));
// 	printf("%i : %i\n", isprint(126), ft_isprint(126));
// 	printf("%i : %i\n", isprint('1'), ft_isprint('1'));
// 	printf("%i : %i\n", isprint('6'), ft_isprint('6'));
// 	printf("%i : %i\n", isprint(32), ft_isprint(32));
// 	printf("%i : %i\n", isprint(31), ft_isprint(31));
// 	printf("%i : %i\n", isprint(5), ft_isprint(5));
// 	printf("%i : %i\n", isprint(14), ft_isprint(14));
// 	printf("%i : %i\n", isprint(0), ft_isprint(0));
// 	return (0);
// }
