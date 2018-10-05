/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:49:05 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:13 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void		init_t_u_num(t_u_num **number)
{
	{
		MALLOC_ERROR((*number = (t_u_num *)ft_memalloc(sizeof(t_u_num))));
		(*number)->num = 0;
		(*number)->num_len = 0;
		(*number)->base = 0;
	}
}

char			*get_prefix(int base, t_flag flag)
{
	if (base == HEX)
		return ((flag.up) ? "0X" : "0x");
	else if (base == OCT)
		return ("0");
	else if (base == BIN)
		return ((flag.up) ? "0B" : "0b");
	else
		return ("");
}

uintmax_t		configure_unsigned(t_spec *spec, va_list ap)
{
	uintmax_t	number;

	if (spec->length.hh)
		number = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (spec->length.h)
		number = (uintmax_t)((unsigned short int)va_arg(ap, unsigned int));
	else if (spec->length.l)
		number = (uintmax_t)va_arg(ap, unsigned long int);
	else if (spec->length.ll)
		number = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (spec->length.j)
		number = va_arg(ap, uintmax_t);
	else if (spec->length.z)
		number = (uintmax_t)va_arg(ap, size_t);
	else if (spec->type == 'p')
		number = (uintmax_t)va_arg(ap, void *);
	else
		number = (uintmax_t)va_arg(ap, unsigned int);
	return (number);
}

static void		change_spec_unsigned(t_spec *spec, t_u_num *u_num)
{
	spec->flag.space = false;
	spec->flag.plus = false;
	if (spec->flag.minus || spec->precision != -1)
		spec->flag.zero = false;
	if (((!(u_num->num) && spec->type != 'p' && \
			!(u_num->base == OCT && !(u_num->num) && !spec->precision)) \
			|| u_num->base == DEC))
		spec->flag.hash = false;
	u_num->num_len = (!(u_num->num) && (!spec->precision)) ? \
		0 : ft_len_unsigned(u_num->num, u_num->base);
	if (u_num->base == OCT)
		spec->precision = MAX(spec->precision - ((spec->flag.hash) ? 1 : 0), \
			u_num->num_len);
	else
		spec->precision = MAX(u_num->num_len, spec->precision);
	spec->width = MAX(spec->width, (spec->precision + ((spec->flag.hash) ?
		(int)ft_strlen(get_prefix(u_num->base, spec->flag)) : 0)));
	spec->sltprint = spec->width - (spec->precision + ((spec->flag.hash) ?
		(int)ft_strlen(get_prefix(u_num->base, spec->flag)) : 0));
}

char			*ft_pr_unsigned(t_spec *spec, va_list ap)
{
	char		*p_str;
	char		*temp_p_str;
	t_u_num		*u_num;

	u_num = NULL;
	init_t_u_num(&u_num);
	u_num->base = calculate_the_base(spec->type);
	u_num->num = configure_unsigned(spec, ap);
	change_spec_unsigned(spec, u_num);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	while (!(spec->flag.minus) && !(spec->flag.zero) && \
			sltp(&spec->sltprint, 0))
		*temp_p_str++ = ' ';
	if (spec->flag.hash)
		ft_str_append(&temp_p_str, get_prefix(u_num->base, spec->flag));
	while (((spec->flag.zero) && sltp(&spec->sltprint, 0)) || \
			(sltp(&spec->precision, u_num->num_len)))
		*temp_p_str++ = '0';
	if (spec->precision)
		ft_u_num_to_str(u_num, (spec->flag.up), &temp_p_str);
	while ((spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = ' ';
	ft_memdel((void **)&u_num);
	return (p_str);
}
