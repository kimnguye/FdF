/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:41:18 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:17 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	if (('0' <= c && c <= '9'))
		return (8);
	else if (('A' <= c && 'Z' >= c) || ('a' <= c && 'z' >= c))
		return (8);
	return (0);
}
// int	main(void)
// {
// 	printf("%i : %i\n", isalnum('e'), ft_isalnum('e'));
// 	printf("%i : %i\n", isalnum('?'), ft_isalnum('?'));
// 	printf("%i : %i\n", isalnum('1'), ft_isalnum('1'));
// 	printf("%i : %i\n", isalnum('6'), ft_isalnum('6'));
// 	printf("%i : %i\n", isalnum(48), ft_isalnum(48));
// 	printf("%i : %i\n", isalnum('0'), ft_isalnum('0'));
// 	printf("%i : %i\n", isalnum(5), ft_isalnum(5));
// 	printf("%i : %i\n", isalnum('-'), ft_isalnum('-'));
// 	printf("%i : %i\n", isalnum('5'), ft_isalnum('5'));
// 	return (0);
// }
