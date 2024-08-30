/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:42:36 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/21 15:13:00 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		n;

	n = ft_strlen(s);
	ptr = (char *) s + n;
	while (*ptr != c % 256 && ptr != s)
		ptr--;
	if (*ptr == c % 256)
		return (ptr);
	return (NULL);
}
