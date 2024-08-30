/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:21 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 10:09:13 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff [BUFFER_SIZE + 1];
	static char	*mem = NULL;
	char		*gnl;
	int			ctr;

	ctr = ft_read(fd, buff, BUFFER_SIZE);
	if (ft_gnl_error(ctr, mem))
		return (NULL);
	mem = ft_concat(mem, buff, ctr);
	while (ft_strchri(mem, EOL) < 0 && ctr > 0)
	{
		ctr = ft_read(fd, buff, BUFFER_SIZE);
		mem = ft_concat(mem, buff, ctr);
	}
	ctr = ft_strchri(mem, EOL) + 1;
	if (ft_strchri(mem, EOL) < 0 && ft_strchri(mem, EOS))
		ctr = ft_strchri(mem, EOS);
	gnl = ft_gnl_substr(mem, ctr);
	mem = ft_shift(mem, ctr);
	return (gnl);
}

/*errors handler:
if read returns -1 we free mem
*/
int	ft_gnl_error(int err, char *mem)
{
	if (BUFFER_SIZE == 0)
		return (1);
	if (err < 0)
		return (free(mem), 1);
	if (ft_strchri(mem, EOS) < 1 && err < 1)
		return (1);
	return (0);
}
