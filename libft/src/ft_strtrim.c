/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:48:06 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/21 15:12:56 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isin(char const *str, char const c)
{
	size_t	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] && c == str[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		start;
	int		i;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_isin(set, s1[end]))
		end--;
	start = 0;
	while (start < end && ft_isin(set, s1[start]))
		start++;
	str = malloc(sizeof(char) * (end - start + 1 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		str[i] = s1[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
