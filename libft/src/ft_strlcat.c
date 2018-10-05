/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:37:22 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/26 21:37:28 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dst_size;
	size_t src_size;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size + 1)
		return (size + src_size);
	if (size > dst_size + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (dst_size + src_size);
}

/*
**NAME
**     strlcpy, strlcat -- size-bounded string copying and concatenation
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     size_t
**     strlcat(char * restrict dst, const char * restrict src, size_t size);
**DESCRIPTION
**	The strlcat() concatenate strings
**	They are designed to be safer, more consistent, and
**	less error prone replacements for strncat(3).
**	Unlike those functions, strlcat() take the full size
**	of the buffer (not just the length) and guarantee to NUL-terminate the
**	result(as long as size is larger than 0 or, in the case of strlcat(),
**	as long as there is at least one byte free in dst).  Note that a byte
**	for the NUL should be included in size.  Also note that
**	strlcat() only operate on true ``C'' strings.  This means that
**	for strlcat() both src and dst must be NUL-terminated.
**	The strlcat() function appends the NUL-terminated string src to the
**	end of dst.  It will append at most size - strlen(dst) - 1 bytes,
**	NUL-terminating the result.
**	The source and destination strings should not overlap, as the behavior
**	is undefined.
**RETURN VALUES
**	The strlcat() functions return the total length of the
**	string they tried to create.
**	For strlcat() that means the initial length of dst plus the length of src.
**	While this may seem somewhat confusing, it was done to make truncation
**	detection simple.
**	Note however, that if strlcat() traverses size characters without finding a
**	NUL, the length of the string is considered to be size and the destination
**	string will not be NUL-terminated (since there was no space for the NUL).
**	This keeps strlcat() from running off the end of a string.  In practice
**	this should not happen (as it means that either size is incorrect or that
**	dst is not a proper ``C'' string).  The check exists to prevent potential
**	security problems in incorrect code.
**	char	*s1 = NULL;
**	char	*s2 = ""; "123"
**	printf("%zu\n", ft_strlcat(s1, s2, 0));
*/
