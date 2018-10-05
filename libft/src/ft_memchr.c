/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:51:47 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 20:51:49 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == *((unsigned char *)s + i))
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
/*
**NAME
**	memchr -- locate byte in byte string
**LIBRARY
**	Standard C Library (libc, -lc)
**SYNOPSIS
**	#include <string.h>
**	void	*memchr(const void *s, int c, size_t n);
**DESCRIPTION
**	The memchr() function locates the first occurrence of c
**	(converted to an unsigned char) in string s.
**RETURN VALUES
**	The memchr() function returns a pointer to the byte located,
**	or NULL if no such byte exists within n bytes.
*/
