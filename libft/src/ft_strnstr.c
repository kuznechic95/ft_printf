/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:34:21 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/27 13:34:23 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			match;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	match = 0;
	while (*(big + i) && i < len)
	{
		if (*(big + i) == *(little))
		{
			k = i;
			j = 0;
			match = 1;
			while (*(big + k) && *(little + j) && i < len && k < len)
				if (*(big + k++) != *(little + j++))
					match = 0;
		}
		if (match && !*(little + j))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*
**NAME
**     strstr, strnstr -- locate a substring in a string
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char		*strstr(const char *big, const char *little);
**     char *strnstr(const char *big, const char *little, size_t len);
**DESCRIPTION
**	The strstr() function locates the first occurrence of the null-terminated
**	string little in the null-terminated string big.
**	The strnstr() function locates the first occurrence of the null-terminated
**	string little in the string big, where not more than len characters are
**	searched.  Characters that appear after a `\0' character are not searched.
**	Since the strnstr() function is a FreeBSD specific API, it should only be
**	used when portability is not a concern.
**RETURN VALUES
**	If little is an empty string, big is returned; if little occurs nowhere
**	in big, NULL is returned; otherwise a pointer to the first character of
**	the first occurrence of little is returned.
**
**	Returns if match && string little meets the end.
**	printf("%s\n",ft_strstr(NULL, "\0", 1));
**	printf("%s\n",ft_strstr(NULL, "\0", 1));
*/
