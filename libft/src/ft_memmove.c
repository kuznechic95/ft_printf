/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:11:51 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 20:11:55 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (src >= dst)
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	else
		while ((int)(--len) >= 0)
			*((char *)dst + len) = *((char *)src + len);
	return (dst);
}

/*
**NAME
**     memmove -- copy byte string
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     void *
**     memmove(void *dst, const void *src, size_t len);
**DESCRIPTION
**     The memmove() function copies len bytes from string src to string dst.
**		The two strings may overlap;
**		the copy is always done in a non-destructive manner.
**RETURN VALUES
**     The memmove() function returns the original value of dst.
*/
