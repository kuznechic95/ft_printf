/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:40:07 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/28 18:40:09 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	const unsigned long	long	min_long = 9223372036854775808ULL;
	unsigned long long			result;
	int							sign;

	result = 0;
	sign = 1;
	while (*str && ft_is_blank((*str)))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = 10 * result + (*str - '0');
		str++;
	}
	if ((result > min_long && sign == -1))
		return (0);
	if ((result > (min_long - 1) && sign == 1))
		return (-1);
	return ((int)result * sign);
}

/*
**NAME
**	atoi, atoi_l -- convert ASCII string to integer
**LIBRARY
**	Standard C Library (libc, -lc)
**SYNOPSIS
**     #include <stdlib.h>
**	int		atoi(const char *str);
**DESCRIPTION
**	The atoi() function converts the initial portion of the string pointed to
**	by str to int representation.
**IMPLEMENTATION NOTES
**	The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
*/
