/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:24:56 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:05:01 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (siz <= len_dst)
		return (len_src + siz);
	i = 0;
	while (src[i] && len_dst + i + 1 < siz)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}

// int	main(int argc, char ** argv)
// {
// 	char	*src;
// 	char	dest[50] = "debut de ma chaine:";
//     char	dest1[50] = "debut de ma chaine:";

// 	if (argc == 2)
// 	{
// 		src = &argv[1][0];
// 		printf("created function returns %zu and dest = %s\n",
//        		ft_strlcat(dest, src, 50), dest);
// 		printf("original function returns %zu and dest = %s\n",
// 		strlcat(dest1, src, 50), dest1);
// 	}
// }
