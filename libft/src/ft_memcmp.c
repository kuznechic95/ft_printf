/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:44:02 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 21:44:04 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}

/*
**NAME
**	memcmp -- compare byte string
**LIBRARY
**	Standard C Library (libc, -lc)
**SYNOPSIS
**	#include <string.h>
**	int	memcmp(const void *s1, const void *s2, size_t n);
**DESCRIPTION
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
**RETURN VALUES
**	The memcmp() function returns zero if the two strings are identical,
**	otherwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0',
**	for example).  Zero-length strings are always identical.
*/
