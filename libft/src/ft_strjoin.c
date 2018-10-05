/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:45:47 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:45:48 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		*(new_str + i) = *(s1 + i);
		i++;
	}
	while (j < s2_len)
		*(new_str + i++) = *(s2 + j++);
	return (new_str);
}

/*
**Prototype
**	char * ft_strjoin(char const *s1, char const *s2);
**Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending
**	with ’\0’, result of the concatenation of s1 and s2. If
**	the allocation fails the function returns NULL.
**Param. #1
**	The prefix string.
**Param. #2
**	The suffix string.
**Return value
**	The “fresh” string result of the concatenation of the 2 strings.
**Libc functions
**	malloc(3)
*/
