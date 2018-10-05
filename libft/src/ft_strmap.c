/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:04:19 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:04:25 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*ptr_char;
	size_t		i;

	if (!s)
		return (NULL);
	ptr_char = ft_strnew(ft_strlen(s));
	if (!ptr_char)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(ptr_char + i) = f(*(s + i));
		i++;
	}
	return (ptr_char);
}

/*
**Description
**	Applies the function f to each character of the string given
**	as argument to create a “fresh” new string (with malloc(3))
**	resulting from the successive applications of f.
**Param. #1
**	The string to map.
**Param. #2
**	The function to apply to each character of s.
**	Return value The “fresh” string created from the successive
**	applications of f.
**Libc functions
**	malloc(3)
*/
