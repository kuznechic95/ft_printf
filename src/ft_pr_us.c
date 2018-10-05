/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_us.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:50:18 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:20 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

size_t			ft_len_str_uchar(wchar_t *str)
{
	size_t		res;

	res = 0;
	while (*str)
		res += ft_len_uchar(*(str++));
	return (res);
}

size_t			get_ws_precision(wchar_t *s, int precision)
{
	size_t		size;

	size = 0;
	while (*s && (int)(size + ft_len_uchar(*s)) <= precision)
		size += ft_len_uchar(*s++);
	return (size);
}

static int		ft_check_locale(wchar_t **s)
{
	int			size;
	size_t		i;

	i = 0;
	while (*(*s + i))
	{
		if (*(*s + i) > 0x10FFFF)
			*s = NULL;
		size = 1 + (*(*s + i) > 0x7F) + (*(*s + i) > 0x7FF) \
			+ (*(*s + i) > 0xFFFF);
		if (size > MB_CUR_MAX)
			return (1);
		i++;
	}
	return (0);
}

static void		change_spec_us(t_spec *spec, wchar_t *s, char *c)
{
	*c = ((spec->flag.zero) && !(spec->flag.minus)) ? '0' : ' ';
	spec->precision = (spec->precision == -1 || \
		ft_len_str_uchar(s) < get_ws_precision(s, spec->precision)) ? \
		ft_len_str_uchar(s) : get_ws_precision(s, spec->precision);
	spec->width = MAX(spec->width, spec->precision);
	spec->sltprint = spec->width - spec->precision;
}

char			*ft_pr_us(t_spec *spec, va_list ap)
{
	char		*p_str;
	char		*temp_p_str;
	char		c;
	wchar_t		*s;
	int			i;

	s = va_arg(ap, wchar_t*);
	if (!s)
		s = (L"(null)");
	if (s && ft_check_locale(&s))
		return ("MB_CUR_MAX_ERROR");
	change_spec_us(spec, s, &c);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	while ((!(spec->flag.minus)) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	i = 0;
	while ((i += ft_len_uchar(*s)) <= spec->precision)
		ft_unicode_mask_for_str(*s++, &temp_p_str);
	while (sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
