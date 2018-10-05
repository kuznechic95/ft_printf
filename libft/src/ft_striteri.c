/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:03:53 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:03:55 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		i;

	i = 0;
	if (s && f)
		while (*(s + i))
		{
			f(i, s + i);
			i++;
		}
}

/*
**Prototype
**	void ft_striteri(char *s, void (*f)(unsigned int, char *));
**Description
**	Applies the function f to each character of the string passed
**as argument, and passing its index as first argument. Each
**character is passed by address to f to be modified if necessary.
**Param. #1
**	The string to iterate.
**Param. #2
**	The function to apply to each character of s and its index.
**Return value
**	None.
**Libc functions
**	None.
*/
