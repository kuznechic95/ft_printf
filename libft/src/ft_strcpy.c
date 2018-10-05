/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:54:17 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/26 18:54:19 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

/*
**NAME
**     strcpy, strncpy -- copy strings
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char *strcpy(char * dst, const char * src);
**     char *strncpy(char * dst, const char * src, size_t len);
**DESCRIPTION
**     The strcpy() functions copy the string src to dst
**		(including the terminating `\0' character.)
**		The strncpy() functions copy at most len characters
**		from src into dst.  If src is less than len characters long, the
**		remainder of dst is filled with `\0' characters.
**		Otherwise, dst is not terminated.
**     The source and destination strings should not overlap,
**		as the behavior is undefined.
**RETURN VALUES
**     The strcpy() and strncpy() functions return dst.
*/
