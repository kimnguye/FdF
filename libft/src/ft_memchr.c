/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:34:44 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:58 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	val;

	val = (unsigned char)c % 256;
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n && ptr[i] != val)
		i++;
	if (i < n && (unsigned char)ptr[i] == val)
		return ((void *)&ptr[i]);
	return (NULL);
}
// int main(void)
// {
//         char s[] = {0, 1, 2 ,3 ,4 ,5};
//         /* 1 */ printf("%s \n\n",  (char*) ft_memchr(s, 0, 0));
//         /* 2 */ printf("%i \n\n", * (char*) ft_memchr(s, 0, 1));
//         /* 3 */ printf("%i \n\n", * (char*) ft_memchr(s, 2, 3));
//         /* 4 */ printf("%s \n\n",  (char*) ft_memchr(s, 6, 6));
//         /* 5 */ printf("%i \n\n", * (char*) ft_memchr(s, 2 + 256, 3));
//         return (0);
// }
