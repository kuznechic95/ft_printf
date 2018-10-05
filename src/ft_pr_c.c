/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:42:17 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:59:51 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

char	*ft_pr_c(t_spec *spec, va_list args)
{
	char	*p_str;
	char	*temp_p_str;
	char	c;

	spec->sltprint = spec->width - 1;
	spec->width = MAX(spec->width, 1);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	c = ((spec->flag.zero) && !(spec->flag.minus)) ? '0' : ' ';
	while ((!(spec->flag.minus)) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	*temp_p_str++ = (char)va_arg(args, int);
	while ((spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
