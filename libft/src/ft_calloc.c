/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:03:29 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:15 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (ptr);
	ptr = malloc(size * nmemb);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
