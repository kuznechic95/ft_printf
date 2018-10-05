/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:21 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/08 17:22:23 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = NULL;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = tmp;
	}
}

/*
**Prototype
**	void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
**Description
**	Takes as a parameter the adress of a pointer to a link and
**	frees the memory of this link and every successors of that link
**	using the functions del and free(3). Finally the pointer to
**	the link that was just freed must be set to NULL (quite similar
**	to the function ft_memdel from the mandatory part).
**Param. #1
**	The address of a pointer to the first link of a list that needs
**	to be freed.
**Return value
**	None.
**Libc functions
**	free(3)
*/
