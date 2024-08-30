/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:18:42 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:29 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbr_len(int n)
{
	int		siz;
	long	nbr;

	nbr = n;
	siz = 0;
	if (nbr < 0)
	{
		siz++;
		nbr = -nbr;
	}
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		siz++;
	}
	return (siz + 1);
}

int	ft_tenpow(unsigned int p)
{
	int	res;

	res = 1;
	while (p > 0)
	{
		res = res * 10;
		p--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		siz;
	int		i;
	long	nbr;

	siz = ft_nbr_len(n);
	tab = malloc((siz + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	nbr = n;
	i = -1;
	n = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		tab[0] = '-';
		i++;
		n = 1;
	}
	while (++i < siz)
	{
		tab[i] = nbr / ft_tenpow(siz - i - 1) + '0';
		nbr = nbr % ft_tenpow(siz - i - 1);
	}
	return (tab[siz] = '\0', tab);
}

// int main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("%i\n%s\n", atoi(argv[1]), ft_itoa(atoi(argv[1])));
// }
// printf("tab[%i] = %c nbr = %ld siz = %i\n", i, tab[i], nbr, siz);
