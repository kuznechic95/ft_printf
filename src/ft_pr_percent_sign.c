/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:42 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:36 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

char		*ft_pr_percent_sign(t_spec *spec, va_list ap)
{
	char	*p_str;
	char	*temp_p_str;
	char	c;

	(void)ap;
	spec->sltprint = spec->width - 1;
	spec->width = MAX(spec->width, 1);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	c = ((spec->flag.zero) && !(spec->flag.minus)) ? '0' : ' ';
	while (!(spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	*temp_p_str++ = '%';
	while (sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
