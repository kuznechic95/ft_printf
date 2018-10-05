/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:03:17 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:03:21 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t		i;

	i = 0;
	if (s && f)
		while (*(s + i))
		{
			f(s + i);
			i++;
		}
}

/*
**Prototype
**	void ft_striter(char *s, void (*f)(char *));
**Description
**	Applies the function f to each character of the string passed
**	as argument. Each character is passed by address to f to be
**	modified if necessary.
**Param. #1
**	The string to iterate.
**Param. #2
**	The function to apply to each character of s.
**Return value
**	None.
**Libc functions
**	None.
*/
