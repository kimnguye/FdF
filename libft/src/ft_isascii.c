/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:45:07 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:21 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isascii(int c)
{
	if ((0 <= c && c <= 127))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%i : %i\n", isascii(200), ft_isascii(200));
// 	printf("%i : %i\n", isascii('?'), ft_isascii('?'));
// 	printf("%i : %i\n", isascii('1'), ft_isascii('1'));
// 	printf("%i : %i\n", isascii('6'), ft_isascii('6'));
// 	printf("%i : %i\n", isascii(48), ft_isascii(48));
// 	printf("%i : %i\n", isascii('0'), ft_isascii('0'));
// 	printf("%i : %i\n", isascii(5), ft_isascii(5));
// 	printf("%i : %i\n", isascii('-'), ft_isascii('-'));
// 	printf("%i : %i\n", isascii('\n'), ft_isascii('\n'));
// 	return (0);
// }
