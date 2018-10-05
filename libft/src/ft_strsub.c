/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:45:38 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:45:40 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
		*(new_str + i++) = *(s + start++);
	return (new_str);
}

/*
**Prototype
**	char * ft_strsub(char const *s, unsigned int start, size_t len);
**Description
**	Allocates (with malloc(3)) and returns a “fresh” substring
**	from the string given as argument. The substring begins at
**	indexstart and is of size len. If start and len aren’t refering
**	to a valid substring, the behavior is undefined. If the
**	allocation fails, the function returns NULL.
**Param. #1
**	The string from which create the substring.
**Param. #2
**	The start index of the substring.
**Param. #3
**	The size of the substring.
**Return value
**	The substring.
**Libc functions
**	malloc(3)
*/
