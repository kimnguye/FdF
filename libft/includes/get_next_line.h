/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:54:19 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/30 10:01:28 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf.h"

char	*get_next_line(int fd);
int		ft_gnl_error(int err, char *mem);

int		ft_read(int fd, char *buff, int siz);
int		ft_strchri(char *s, char c);
char	*ft_shift(char *s, int n);
char	*ft_gnl_substr(char *s, int n);
char	*ft_concat(char *mem, char *s, int n);

# ifndef MAX_SIZE
#  define MAX_SIZE 1000000
# endif

# ifndef EOL
#  define EOL '\n'
# endif

# ifndef EOS
#  define EOS '\0'
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE MAX_SIZE
# endif
# if BUFFER_SIZE > MAX_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE MAX_SIZE
# endif

#endif