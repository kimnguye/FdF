/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:35:23 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:51 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		n;
	char	*dup;

	n = ft_strlen(s);
	dup = malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	str1[] = "coucou ca va ?";
// 	char	str2[] = "bien la famille";
// 	char	dest[50];
// 	size_t	n;

// 	n = 10;
// 	printf("src = %s; dest = %s\n", str1, dest);
// 	printf("devient : dest = %s\n", ft_strdup(str1));
// 	printf("src = %s; dest = %s\n", str2, dest);
// 	printf("devient : dest = %s\n", ft_strdup(str2));
// 	return (0);
// }
