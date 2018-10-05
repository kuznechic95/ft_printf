/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:55:29 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:17 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

int32_t			identify_type(char type, t_spec *spec)
{
	if ((type == 'c' || type == 's') && (spec->length.l || spec->length.ll))
		spec->type = ft_toupper(type);
	else if (type == 'X' || type == 'B')
	{
		spec->flag.up = true;
		spec->type = ft_tolower(type);
	}
	else if (type == 'U' || type == 'O' || type == 'D')
	{
		if (!(spec->length.ll))
			spec->length.l = true;
		spec->type = ft_tolower(type);
	}
	else
		spec->type = type;
	configure_length(spec);
	return ((int)type);
}
