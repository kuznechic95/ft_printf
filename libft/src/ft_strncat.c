/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:37:05 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/26 21:37:09 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(s1);
	j = 0;
	while (*(s2 + j) && (j < n))
		*(s1 + i++) = *(s2 + j++);
	*(s1 + i) = '\0';
	return (s1);
}

/*
**NAME
**     strcat, strncat -- concatenate strings
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char *
**     strcat(char *restrict s1, const char *restrict s2);
**     char *
**     strncat(char *restrict s1, const char *restrict s2, size_t n);
**DESCRIPTION
**   	The strcat() and strncat() functions append a copy of the
**		null-terminated string s2 to the end of the null-terminated string s1,
**		then add a terminating `\0'. The string s1 must have sufficient space
**		to hold the result.
**		The strncat() function appends not more than n characters from s2,
**		and then adds a terminating `\0'.
**		The source and destination strings should not overlap, as
**		the behavior is undefined.
**RETURN VALUES
**     The strcat() and strncat() functions return the pointer s1.
*/
