/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:13:07 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:00 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
