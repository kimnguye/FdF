/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:31:54 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:05:43 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen (s);
	if (start > l)
		sub = malloc(1);
	else if (l <= len)
		sub = malloc (sizeof(char) * (l - start + 1));
	else if (start + len <= l)
		sub = malloc (sizeof(char) * (len + 1));
	else
		sub = malloc (sizeof(char) * (l - start + 1));
	if (!sub)
		return (NULL);
	while (i < len && i + start < l)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// si indice start depasse la len de s, on retourne une chaine vide
// si le nb de char a copier est > len de s, on ne copie que len de s char
// sinon, on copie len de s - start char
