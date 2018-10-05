/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:25:26 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/26 18:25:29 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr_str;

	ptr_str = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr_str == NULL)
		return (NULL);
	ft_bzero(ptr_str, size + 1);
	return (ptr_str);
}

/*
**Prototype
**	char * ft_strnew(size_t size);
**Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending
**	with ’\0’. Each character of the string is initialized at
**	’\0’. If the allocation fails the function returns NULL.
**Param. #1
**	The size of the string to be allocated.
**Return value
**	The string allocated and initialized to 0.
**Libc functions malloc(3)
*/
