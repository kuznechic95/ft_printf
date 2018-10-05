/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:34:02 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/27 13:34:04 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			match;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	match = 0;
	while (*(big + i))
	{
		if (*(big + i) == *(little))
		{
			k = i;
			j = 0;
			match = 1;
			while (*(little + j))
				if (*(big + k++) != *(little + j++))
					match = 0;
		}
		if (match)
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
** printf("%s\n",ft_strstr(NULL, "\0"));
** printf("%s\n",ft_strstr(NULL, "\0"));
*/
