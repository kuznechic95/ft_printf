/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:48:56 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 18:52:31 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		*((char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
**NAME
**     memset -- fill a byte string with a byte value
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     void *
**     memset(void *b, int c, size_t len);
**DESCRIPTION
**     The memset() function writes len bytes of value c (converted to
**		an unsigned char) to the string b.
**RETURN VALUES
**     The memset() function returns its first argument.
*/
