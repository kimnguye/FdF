/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:56:11 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/21 15:13:08 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	siz;

	i = 0;
	ptr = (char *) big;
	if (!*little)
		return (ptr);
	siz = ft_strlen(little);
	while (ptr[i] && i + siz - 1 < len)
	{
		if (ptr[i] == *little)
		{
			if (!ft_strncmp(&ptr[i], little, siz))
				return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
