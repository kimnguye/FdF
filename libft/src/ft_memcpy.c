/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:36:10 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:07 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// int	main(void)
// {
// 	char	s[MAX_LEN];
// 	char	t[MAX_LEN];
// 	char	str1[] = "coucou ca va ?";
// 	char	str2[] = "bien ou bien la famille ? et la grand mere ?";

// 	ft_memcpy(t, str2, sizeof(str2));
// 	memcpy(s, str2, sizeof(str2));
// 	printf("\norig:'%s'\ncopy:'%s'\n", s, t);
// 	memcpy(s, str1, sizeof(str1));
// 	ft_memcpy(t, str1, sizeof(str1));
// 	printf("\norig:'%s'\ncopy:'%s'\n", s, t);
// 	return (0);
// }
