/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:49:50 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 15:49:51 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}

/*
**Prototype
**	void ft_strclr(char *s);
**Description
**	Sets every character of the string to the value ’\0’.
**Param. #1
**	The string that needs to be cleared.
**Return value
**	None.
**Libc functions
**	None.
*/
