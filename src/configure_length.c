/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:41:31 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:58:54 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** z > j > ll > l > h > hh
*/

#include "../inc/ft_printflib.h"

void			configure_length_h(t_spec *spec)
{
	spec->length.hh = false;
}

void			configure_length_l(t_spec *spec)
{
	spec->length.h = false;
	configure_length_h(spec);
}

void			configure_length_ll(t_spec *spec)
{
	spec->length.l = false;
	configure_length_l(spec);
}

void			configure_length_j(t_spec *spec)
{
	spec->length.ll = false;
	configure_length_ll(spec);
}

void			configure_length(t_spec *spec)
{
	if (spec->length.h)
		configure_length_h(spec);
	if (spec->length.l)
		configure_length_l(spec);
	if (spec->length.ll)
		configure_length_ll(spec);
	if (spec->length.j)
		configure_length_j(spec);
	if (spec->length.z)
		configure_length_j(spec);
}
