/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:33:14 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/27 13:33:15 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		size;

	size = ft_strlen(s);
	i = 0;
	while (i < size + 1)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*
**NAME
**     strchr -- locate character in string (first occurrence of c)
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char		*strchr(const char *s, int c);
**DESCRIPTION
**	The strchr() function locates the first occurrence of c (converted to a
**	char) in the string pointed to by s.  The terminating null character is
**	considered to be part of the string; therefore if c is `\0', the functions
**	locate the terminating `\0'.
**	The strrchr() function is identical to strchr(), except it locates the
**	last occurrence of c.
*/
