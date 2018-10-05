/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:46 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/08 17:22:48 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst || !f)
		return ;
	if (lst->next)
		ft_lstiter(lst->next, f);
	f(lst);
}

/*
**Prototype
**	void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
**Description
**	Iterates the list lst and applies the function f to each link.
**Param. #1
**	A pointer to the first link of a list.
**Param. #2
**	The address of a function to apply to each link of a list.
**Return value
**	None.
**Libc functions
**	None.
*/
