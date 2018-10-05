/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:35:47 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:35:49 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (!ft_strncmp(s1, s2, n) ? 1 : 0);
}

/*
**Prototype
**	int ft_strnequ(char const *s1, char const *s2,size_t n);
**Description
**	Lexicographical comparison between s1 and s2 up to n characters
**	or until a ’\0’ is reached. If the 2 strings are identical,
**	the function returns 1, or 0 otherwise.
**Param. #1
**	The first string to be compared.
**Param. #2
**	The second string to be compared.
**Param. #3
**	The maximum number of characters to be compared.
**Return value
**	1 or 0 according to if the 2 strings are identical or not.
**Libc functions
**	None.
*/
