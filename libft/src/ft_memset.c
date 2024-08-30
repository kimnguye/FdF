/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:48:12 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:12 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	s[10];
// 	char	t[10];
// 	int		i;
// 	int		n;
// 	char	val;

// 	i = -1;
// 	val = 'O';
// 	n = 10;
// 	memset(s, val, n);
// 	ft_memset(t, val, n);
// 	while (++i < 10)
// 		printf("%c : %c \n", s[i], t[i]);
// 	return (0);
// }
