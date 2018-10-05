/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:19:36 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 19:49:45 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}

/*
**NAME
**	memcpy -- copy memory area
**LIBRARY
**	Standard C Library (libc, -lc)
**SYNOPSIS
**	#include <string.h>
**	void	*memcpy(void *restrict dst, const void *restrict src, size_t n);
**DESCRIPTION
**	The memcpy() function copies n bytes from memory area src to memory
**	area dst.  If dst and src overlap, behavior is undefined.
**	Applications in which dst and src might overlap should use
**	memmove(3) instead.
**RETURN VALUES
**	The memcpy() function returns the original value of dst.
*/
