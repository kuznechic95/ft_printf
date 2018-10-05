/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:33 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/08 17:22:38 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

/*
**Prototype
**	void ft_lstadd(t_list **alst, t_list *new);
**Description
**	Adds the element new at the beginning of the list.
**Param. #1
**	The address of a pointer to the first link of a list.
**Param. #2
**	The link to add at the beginning of the list.
**Return value
**	None.
**Libc functions
**	None.
*/
