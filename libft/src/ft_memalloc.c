/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:35:10 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 15:35:13 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
		ptr = malloc(size);
	else
		return (NULL);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

/*
**Prototype
**	void * ft_memalloc(size_t size);
**Description
**	Allocates (with malloc(3)) and returns a “fresh” memory
**	area. The memory allocated is initialized to 0. If the allocation
**	fails, the function returns NULL.
**Param.
**	#1 The size of the memory that needs to be allocated.
**Return value
**	The allocated memory area.
**Libc functions
**	malloc(3)
*/
