/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:21:58 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/08 17:22:00 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

/*
**Prototype
**	t_list * ft_lstnew(void const *content, size_t content_size);
**Description
**	Allocates (with malloc(3)) and returns a “fresh” link. The
**	variables content and content_size of the new link are initialized
**	by copy of the parameters of the function. If the parameter
**	content is nul, the variable content is initialized to
**	NULL and the variable content_size is initialized to 0 even
**	if the parameter content_size isn’t. The variable next is
**	initialized to NULL. If the allocation fails, the function returns NULL.
**Param. #1
**	The content to put in the new link.
**Param. #2 The size of the content of the new link.
**Return value
**	The new link.
**Libc functions
**	malloc(3), free(3)
*/
