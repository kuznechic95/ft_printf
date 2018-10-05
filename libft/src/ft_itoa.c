/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:46:21 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:46:22 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n_copy;

	str_len = ft_str_len(n);
	n_copy = (n < 0) ? -n : n;
	if (n < 0)
		str_len++;
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n_copy % 10 + '0';
	while (n_copy /= 10)
		str[--str_len] = n_copy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}

/*
**Prototype
**	char * ft_itoa(int n);
**Description
**	Allocate (with malloc(3)) and returns a “fresh” string ending
**	with ’\0’ representing the integer n given as argument.
**	Negative numbers must be supported. If the allocation fails,
**	the function returns NULL.
**Param. #1
**	The integer to be transformed into a string.
**Return value
**	The string representing the integer passed as argument.
**Libc functions
**	malloc(3)
*/
