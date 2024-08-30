/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:59:08 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:05:06 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	if (siz < 1)
		return (ft_strlen(src));
	i = 0;
	while (i < siz - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	str1[] = "coucou ca va ?";
// 	char	str2[] = "bien la famille";
// 	char	dest[MAX_LEN];
// 	size_t	n;

// 	n = 10;
// 	printf("src : %s; nb a copier au plus : %zu \n", str1, n);
// 	printf("dest : %s; len(src): %zu\n", dest, ft_strlcpy(dest, str1, n));
// 	printf("src : %s; nb a copier au plus: %zu \n", str2, n);
// 	printf("dest : %s; len(src) : %zu\n", dest, ft_strlcpy(dest, str2, n));
// 	return (0);
// }
