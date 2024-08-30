/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:38:40 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:57 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*join;
	size_t	i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc ((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < l1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	return (join);
}
