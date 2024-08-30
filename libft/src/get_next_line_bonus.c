/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:07:36 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:41:15 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buff [BUFFER_SIZE + 1];
	char		*gnl;
	static char	*mem[FD_NBR];
	int			ctr;

	ctr = ft_read(fd, buff, BUFFER_SIZE);
	if (ft_gnl_error(ctr, mem[fd]))
		return (NULL);
	mem[fd] = ft_concat(mem[fd], buff, ctr);
	while (ft_strchri(mem[fd], EOL) < 0 && ctr > 0)
	{
		ctr = ft_read(fd, buff, BUFFER_SIZE);
		mem[fd] = ft_concat(mem[fd], buff, ctr);
	}
	ctr = ft_strchri(mem[fd], EOL) + 1;
	if (ft_strchri(mem[fd], EOL) < 0 && ft_strchri(mem[fd], EOS))
		ctr = ft_strchri(mem[fd], EOS);
	gnl = ft_gnl_substr(mem[fd], ctr);
	mem[fd] = ft_shift(mem[fd], ctr);
	return (gnl);
}

//if read returns -1 we reinitialize err and mem
int	ft_gnl_error(int err, char *mem)
{
	if (BUFFER_SIZE == 0)
		return (1);
	if (err < 0)
	{
		if (mem && *mem)
			*mem = '\0';
		else
			mem = NULL;
		return (1);
	}
	if (ft_strchri(mem, EOS) < 1 && err < 1)
		return (1);
	return (0);
}
