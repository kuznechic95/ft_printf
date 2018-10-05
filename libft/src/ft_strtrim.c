/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:45:57 by okuzniet          #+#    #+#             */
/*   Updated: 2017/11/13 18:14:58 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*ptr_char;

	if (!s)
		return (NULL);
	if (!ft_strlen(s))
		return ((char *)"\0");
	i = 0;
	j = ft_strlen(s) - 1;
	while (IS_SPACE(*(s + i)))
		i++;
	while (IS_SPACE(*(s + j)))
		j--;
	if (j < i)
	{
		ptr_char = (char *)ft_memalloc(1);
		return (ptr_char);
	}
	ptr_char = ft_strsub(s, i, (j - i + 1));
	return (ptr_char);
}

/*
**Prototype
**	char * ft_strtrim(char const *s);
**Description
**	Allocates (with malloc(3)) and returns a copy of the string
**	given as argument without whitespaces at the beginning or at
**	the end of the string. Will be considered as whitespaces the
**	following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
**	at the beginning or at the end, the function returns a
**	copy of s. If the allocation fails the function returns NULL.
**Param. #1
**	The string to be trimed.
**Return value
**	The “fresh” trimmed string or a copy of s.
**Libc functions
**	malloc(3)
*/
