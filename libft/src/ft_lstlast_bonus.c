/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:25:29 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:43 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	siz;
	int	i;

	i = 1;
	siz = ft_lstsize(lst);
	while (i < siz)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
