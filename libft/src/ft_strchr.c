/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:11:04 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:04:48 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr != c % 256 && *ptr)
		ptr++;
	if (*ptr == c % 256)
		return (ptr);
	return (NULL);
}

// int main(void)
// {
//         char s[] = "tripouille";
//         /* 1 */ printf("%s\n", ft_strchr(s, 't'));
//         /* 2 */ printf("%s\n", ft_strchr(s, 'l'));
//         /* 3 */ printf("%s\n", ft_strchr(s, 'z'));
//         /* 4 */ printf("%s\n", ft_strchr(s, 0));
//         /* 5 */ printf("%s\n", ft_strchr(s, 't' + 256));
//         return (0);
// }
