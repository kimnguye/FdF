/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:41:14 by kimnguye          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:37 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int		n;
	int		i;
	t_list	*ptr;

	if (!*lst)
		return ;
	i = 0;
	n = ft_lstsize(*lst);
	while (i < n)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ptr;
		i++;
	}
}
