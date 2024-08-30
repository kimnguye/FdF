/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:49:52 by kimnguye          #+#    #+#             */
/*   Updated: 2024/08/02 15:22:22 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*create a new list resulting from the application of f to each element*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	t_list	*old;

	if (!lst)
		return (NULL);
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	old = res;
	old->content = f(lst->content);
	old->next = NULL;
	lst = lst->next;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (ft_lstclear(&res, del), NULL);
		new->content = f(lst->content);
		new->next = NULL;
		old->next = new;
		old = old->next;
		lst = lst->next;
	}
	return (res);
}
