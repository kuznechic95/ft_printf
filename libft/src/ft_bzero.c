/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:09:30 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 19:09:32 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		*((char *)s + i) = 0;
		i++;
	}
}

/*
**NAME
**     _bzero -- write zeroes to a byte string
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <strings.h>
**     void
**     _bzero(void *s, size_t n);
**DESCRIPTION
**     The _bzero() function writes n zeroed bytes to the string s.
**		If n is zero, _bzero() does nothing.
*/
