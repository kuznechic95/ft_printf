/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:23:02 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/08 17:23:04 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ptr_to_first_element;
	t_list		*new_list;

	if (!lst || !f)
		return (NULL);
	new_list = f(lst);
	ptr_to_first_element = new_list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_list->next = f(lst)))
			return (NULL);
		new_list = new_list->next;
	}
	return (ptr_to_first_element);
}

/*
**Prototype
**	t_list * ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
**Description
**	Iterates a list lst and applies the function f to each link to
**	create a “fresh” list (using malloc(3)) resulting from the successive
**	applications of f. If the allocation fails, the function
**	returns NULL.
**Param. #1
**	A pointer’s to the first link of a list.
**Param. #2
**	The address of a function to apply to each link of a list.
**Return value
**	The new list.
**Libc functions
**	malloc(3), free(3).
*/
