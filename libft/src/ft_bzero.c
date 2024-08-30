/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:49:42 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:13 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	s[30] = "coucou toi comment tu vas ?";
// 	char	t[30] = "coucou toi comment tu vas ?";
// 	int		i;
// 	int		n;

// 	i = -1;
// 	n = 11;
// 	bzero(s, n);
// 	ft_bzero(t, n);
// 	while (++i < 27)
// 		printf("%c : %c \n", s[i], t[i]);
// 	return (0);
// }
