/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:07:03 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 22:07:05 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

/*
**NAME
**	strlen -- find length of string
**LIBRARY
**	Standard C Library (libc, -lc)
**SYNOPSIS
**	#include <string.h>
**	size_t	strlen(const char *s);
**DESCRIPTION
**	The strlen() function computes the length of the string s.
**RETURN VALUES
**	The strlen() function returns the number of characters that
**	precede the terminating NUL character.
*/
