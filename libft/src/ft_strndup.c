/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:20:15 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/26 18:20:17 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr_char;

	ptr_char = ft_strnew(n);
	if (ptr_char == NULL)
		return (NULL);
	ft_strncpy(ptr_char, s1, n);
	return (ptr_char);
}

/*
**NAME
**     strdup, strndup -- save a copy of a string
**LIBRARY
**     Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <string.h>
**     char *
**     strdup(const char *s1);
**     char *
**     strndup(const char *s1, size_t n);
**DESCRIPTION
**     The strdup() function allocates sufficient memory for a copy of the
**		string s1, does the copy, and returns a pointer to it.
**		The pointer may subsequently be used as an argument to the function
**		free(3).
**    If insufficient memory is available, NULL is returned and errno is
**		set to ENOMEM. The strndup() function copies at most n characters
**		from the string s1 always NUL terminating the copied string.
*/
