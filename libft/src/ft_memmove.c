/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:42:17 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:09 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	if (dest > src)
	{
		i = n + 1;
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return (d);
}

// int	main(void)
// {
// 	char	s[MAX_LEN];
// 	char	t[MAX_LEN];
// 	char	str1[] = "dest > source";
// 	char	str2[] = "source > dest ";
// 	char	s2[] = "               ";
// 	char	t2[] = "               ";

// 	printf("\nbefore orig:'%s'\nbefore copy:'%s'\n", s, t);
// 	memmove(s, str1, sizeof(str1));
// 	ft_memmove(t, str1, sizeof(str1));
// 	printf("\nafter orig:'%s'\nafter copy:'%s'\n", s, t);
// 	printf("\nbefore orig:'%s'\nbefore copy:'%s'\n", s2, t2);
// 	memmove(s2, str2, sizeof(str2));
// 	ft_memmove(t2, str2, sizeof(str2));
// 	printf("\nafter orig:'%s'\nafter copy:'%s'\n", s2, t2);
// 	return (0);
// }
