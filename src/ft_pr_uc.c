/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_uc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:50:13 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:05 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

int			ft_len_uchar(wchar_t c)
{
	if (c <= 0b1111111)
		return (1);
	else if (c <= 0b11111111111)
		return (2);
	else if (c <= 0b1111111111111111)
		return (3);
	else if (c <= 0b100001111111111111111)
		return (4);
	else
		return (0);
}

char		*ft_pr_uc(t_spec *spec, va_list ap)
{
	char	*p_str;
	char	*temp_p_str;
	char	c;
	wchar_t	s;
	int		size;

	s = (wchar_t)va_arg(ap, unsigned int);
	if (s > 0x10FFFF)
		return (NULL);
	size = 1 + (s > 0x7F) + (s > 0x7FF) + (s > 0xFFFF);
	if (size > MB_CUR_MAX)
		return ("MB_CUR_MAX_ERROR");
	spec->sltprint = spec->width - ft_len_uchar(s);
	spec->width = MAX(spec->width, ft_len_uchar(s));
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	c = (!(spec->flag.zero)) ? ' ' : '0';
	while (!(spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	ft_unicode_mask_for_str(s, &temp_p_str);
	while (sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
