/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:08:33 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:05:09 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	// printf("%lu : %lu\n", strlen("coucou \n ca \t  va \n  ? "),
// 	// ft_strlen("coucou \n ca \t  va \n  ? "));
// 	// printf("%lu : %lu\n", strlen("okay"), ft_strlen("okay"));
// 	// printf("%lu : %lu\n", strlen("32"), ft_strlen("32"));
// 	// printf("%lu : %lu\n", strlen("31"), ft_strlen("31"));
// 	// printf("%lu : %lu\n", strlen(""), ft_strlen(""));
// 	return (0);
// }
