/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_false.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:51:31 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:35 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void	make_false_flags(t_flag *flag)
{
	flag->zero = false;
	flag->minus = false;
	flag->plus = false;
	flag->space = false;
	flag->hash = false;
	flag->up = false;
}

static void	make_false_length(t_length *length)
{
	length->l = false;
	length->ll = false;
	length->h = false;
	length->hh = false;
	length->j = false;
	length->z = false;
}

void		make_false(t_spec *spec)
{
	make_false_flags(&(spec->flag));
	spec->width = 0;
	spec->precision = -1;
	make_false_length(&(spec->length));
	spec->type = '\0';
	spec->sltprint = 0;
}
