/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:59:37 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:58:28 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/* returns the index of the 1st occ of the char c founded in string s */
/* returns -1 if not found or if string s does not exist */
int	ft_strchri(char *s, char c)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

//returns the number of bytes read and null terminates the buffer
int	ft_read(int fd, char *buff, int siz)
{
	int	err;

	err = read(fd, buff, siz);
	if (err >= 0)
		buff[err] = '\0';
	else
		buff[0] = '\0';
	return (err);
}

//make a dup of the n first bytes of string s nd null terminates it.
char	*ft_gnl_substr(char *s, int n)
{
	char	*sub;
	int		i;

	i = 0;
	sub = malloc (sizeof(char) * (n + 1));
	if (!sub || !s)
		return (NULL);
	while (s[i] && i < n)
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

//copy the first n bytes of string s at the end of dest and null terminates it.
char	*ft_concat(char *dest, char *s, int n)
{
	char	*tmp;
	int		i;
	int		dstsiz;

	if (!dest)
		return (ft_gnl_substr(s, n));
	if (n <= 0)
		return (dest);
	dstsiz = ft_strchri(dest, EOS);
	tmp = ft_gnl_substr(dest, dstsiz);
	if (!tmp)
		return (NULL);
	free(dest);
	dest = malloc(dstsiz + n + 1);
	if (!dest)
		return (free(tmp), NULL);
	i = -1;
	while (++i < dstsiz)
		dest[i] = tmp[i];
	i--;
	while (++i < dstsiz + n)
		dest[i] = s[i - dstsiz];
	dest[i] = '\0';
	return (free(tmp), dest);
}

//returns the string s after deleting the first n bytes of it
char	*ft_shift(char *s, int n)
{
	char	*sub;
	int		i;
	int		siz;

	i = 0;
	siz = ft_strchri(s, EOS) - n;
	if (!siz || !s)
		return (free(s), NULL);
	sub = malloc (sizeof(char) * (siz + 1));
	if (!sub)
		return (free(s), NULL);
	while (s[i] && i < siz)
	{
		sub[i] = s[i + n];
		i++;
	}
	sub[i] = '\0';
	return (free(s), sub);
}
