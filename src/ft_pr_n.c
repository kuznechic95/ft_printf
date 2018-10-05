/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:21 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:04 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

char		*ft_pr_n(t_spec *spec, va_list args)
{
	int		*number;

	number = va_arg(args, int *);
	if (spec->length.hh)
		*(signed char *)number = (signed char)spec->sltprint;
	else if (spec->length.h)
		*(short *)number = (short)spec->sltprint;
	else if (spec->length.l)
		*(long *)number = (long)spec->sltprint;
	else if (spec->length.ll)
		*(long long *)number = (long long)spec->sltprint;
	else if (spec->length.j)
		*(intmax_t *)number = (intmax_t)spec->sltprint;
	else if (spec->length.z)
		*(ssize_t *)number = (ssize_t)spec->sltprint;
	else
		*number = spec->sltprint;
	return (ft_strdup(""));
}

/*
**Nothing printed.
**The corresponding argument must be a pointer to a signed int.
**The number of characters written so far is stored in the pointed location.
*/
