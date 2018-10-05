/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:33:40 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/27 13:33:42 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
**NAME
**     strrchr -- locate character in string (last occurrence of c)
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char		*strrchr(const char *s, int c);
**DESCRIPTION
**	The strchr() function locates the first occurrence of c (converted to a
**	char) in the string pointed to by s.  The terminating null character is
**	considered to be part of the string; therefore if c is `\0', the functions
**	locate the terminating `\0'.
**	The strrchr() function is identical to strchr(), except it locates the
**	last occurrence of c.
*/
