/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:55:25 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:09 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

void		identify_prec(char **pp_str, t_spec *spec, va_list ap)
{
	int32_t precision;

	precision = -1;
	if (**pp_str == '.')
	{
		(*pp_str)++;
		precision = 0;
		if (**pp_str == '*')
		{
			(*pp_str)++;
			precision = va_arg(ap, int);
		}
		else if (ft_isdigit(**pp_str))
			precision = ft_pr_atoi(pp_str);
		if (precision < 0)
			precision = -1;
	}
	spec->precision = precision;
}
