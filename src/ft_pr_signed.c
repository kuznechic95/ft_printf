/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:59 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:58 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

/*
** z > j > ll > l > h > hh
*/

static void			init_t_s_num(t_s_num **number)
{
	{
		MALLOC_ERROR((*number = (t_s_num *)ft_memalloc(sizeof(t_s_num))));
		(*number)->num = 0;
		(*number)->num_len = 0;
		(*number)->base = 0;
		(*number)->sign = 0;
	}
}

static intmax_t		configure_signed(t_spec *spec, va_list ap)
{
	intmax_t	number;

	if (spec->length.hh)
		number = (intmax_t)((signed char)va_arg(ap, int));
	else if (spec->length.h)
		number = (intmax_t)((short int)va_arg(ap, int));
	else if (spec->length.l)
		number = (intmax_t)va_arg(ap, long int);
	else if (spec->length.ll)
		number = (intmax_t)va_arg(ap, long long int);
	else if (spec->length.j)
		number = va_arg(ap, intmax_t);
	else if (spec->length.z)
		number = (intmax_t)va_arg(ap, ssize_t);
	else
		number = (intmax_t)va_arg(ap, int);
	return (number);
}

int					ft_len_unsigned(uintmax_t number, int base)
{
	int size;

	size = 1;
	while ((number /= base))
		size++;
	return (size);
}

static void			change_spec_signed(t_spec *spec, t_s_num *s_num)
{
	if (spec->flag.minus || spec->precision != -1)
		spec->flag.zero = false;
	if (!(s_num->num) && !spec->precision)
		s_num->num_len = 0;
	else
		s_num->num_len = ft_len_unsigned(ABS(s_num->num), s_num->base);
	if (s_num->num < 0)
		s_num->sign = '-';
	else if (spec->flag.plus)
		s_num->sign = '+';
	else if (spec->flag.space)
		s_num->sign = ' ';
	spec->precision = MAX(s_num->num_len, spec->precision);
	if (s_num->sign)
	{
		spec->width = MAX(spec->width, spec->precision + 1);
		spec->sltprint = spec->width - (spec->precision + 1);
	}
	else
	{
		spec->width = MAX(spec->width, spec->precision);
		spec->sltprint = spec->width - spec->precision;
	}
}

char				*ft_pr_signed(t_spec *spec, va_list ap)
{
	char			*p_str;
	char			*temp_p_str;
	t_s_num			*s_num;

	s_num = NULL;
	init_t_s_num(&s_num);
	s_num->base = calculate_the_base(spec->type);
	s_num->num = configure_signed(spec, ap);
	change_spec_signed(spec, s_num);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	while (!(spec->flag.minus) && !(spec->flag.zero) && \
			sltp(&spec->sltprint, 0))
		*temp_p_str++ = ' ';
	if (s_num->sign)
		*temp_p_str++ = s_num->sign;
	while (((spec->flag.zero) && (sltp(&spec->sltprint, 0))) || \
			sltp(&spec->precision, s_num->num_len))
		*temp_p_str++ = '0';
	if (spec->precision)
		ft_s_num_to_str(s_num, (spec->flag.up), &temp_p_str);
	while ((spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = ' ';
	ft_memdel((void **)&s_num);
	return (p_str);
}
