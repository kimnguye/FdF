/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:56:47 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/18 18:15:07 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*returns the nb of words seperated by c in the string s*/
int	ft_countsplits(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	return (n);
}

/*malloc the size of each word*/
int	ft_malloc_split(char **split, int w, int l)
{
	int	i;

	split[w] = malloc (sizeof(char) * (l + 1));
	if (!split[w])
	{
		i = 0;
		while (i <= w)
		{
			free(split[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

int	ft_fill_split(char **split, int n, char const *s, char c)
{
	int	i;
	int	j;
	int	l;
	int	w;

	w = 0;
	i = -1;
	while (s[++i] && w < n)
	{
		if (s[i] != c && w < n)
		{
			l = 0;
			while (s[i + l] && s[i + l] != c)
				l++;
			if (!ft_malloc_split(split, w, l))
				return (0);
			j = l;
			split[w][j] = '\0';
			while (--j >= 0)
				split[w][j] = s[j + i];
			w++;
			i += l - 1;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n;

	n = ft_countsplits(s, c);
	split = malloc (sizeof(char *) * (n + 1));
	if (!split)
		return (free(split), NULL);
	if (n > 0 && !ft_fill_split(split, n, s, c))
		return (free(split), NULL);
	split[n] = NULL;
	return (split);
}
