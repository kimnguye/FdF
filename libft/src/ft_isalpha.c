/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:21:56 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:19 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && 'Z' >= c) || ('a' <= c && 'z' >= c))
		return (1024);
	return (0);
}

// int     main(void)
// {
//         printf("%i : %i\n",isalpha('e'), ft_isalpha('e'));
//         printf("%i : %i\n",isalpha('?'), ft_isalpha('?'));
//         printf("%i : %i\n",isalpha(1), ft_isalpha(1));
//         printf("%i : %i\n",isalpha(66), ft_isalpha(66));
//         printf("%i : %i\n",isalpha(97), ft_isalpha(97));
//         printf("%i : %i\n",isalpha(0), ft_isalpha(0));
//         printf("%i : %i\n",isalpha(-1), ft_isalpha(-1));
//         printf("%i : %i\n",isalpha('Z'), ft_isalpha('Z'));
//         printf("%i : %i\n",isalpha('='), ft_isalpha('='));
//         return (0);
// }
