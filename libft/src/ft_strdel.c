/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:47:12 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 15:47:14 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

/*
**Prototype
**	void ft_strdel(char **as);
**Description
**	Takes as a parameter the address of a string that need to be
**	freed with free(3), then sets its pointer to NULL.
**Param. #1
**	The string’s address that needs to be freed and its pointer set to NULL.
**Return value
**	None.
**Libc functions
**	Free(3)
*/
