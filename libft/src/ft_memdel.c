/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:39:56 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 15:39:58 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}

/*
**Prototype
**	void ft_memdel(void **ap);
**Description
**	Takes as a parameter the address of a memory area that needs
**	to be freed with free(3), then puts the pointer to NULL.
**Param. #1
**	A pointer’s address that needs its memory freed and set to NULL.
**Return value
**	None.
**Libc functions free(3).
*/
