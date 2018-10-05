/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:55 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:53 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

void			up_down_strncat(char **dest, const char *src, size_t n)
{
	while (n && *src)
	{
		*(*dest)++ = *src++;
		n--;
	}
}

char			*ft_pr_s(t_spec *spec, va_list ap)
{
	char	*p_str;
	char	*temp_p_str;
	char	*p_ap;
	char	c;

	if (!(p_ap = va_arg(ap, char*)))
		p_ap = ("(null)");
	if (spec->precision == -1 || ((int)ft_strlen(p_ap) < spec->precision))
		spec->precision = (int)ft_strlen(p_ap);
	c = ((spec->flag.zero) && !(spec->flag.minus)) ? '0' : ' ';
	spec->width = MAX(spec->width, spec->precision);
	spec->sltprint = spec->width - spec->precision;
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	while (!(spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	up_down_strncat(&temp_p_str, p_ap, spec->precision);
	while (sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
