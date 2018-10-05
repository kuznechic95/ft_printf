/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:55:32 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:29 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

int			ft_pr_atoi(char **p_str)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	if (**p_str == '-')
	{
		sign = -1;
		(*p_str)++;
	}
	while (**p_str >= '0' && **p_str <= '9')
		num = num * 10 + (*((*p_str)++) - '0');
	return (sign * num);
}

void		identify_width(char **pp_str, t_spec *spec, va_list ap)
{
	spec->width = 0;
	if (ft_isdigit(**pp_str))
		spec->width = ft_pr_atoi(pp_str);
	if (**pp_str == '*')
	{
		(*pp_str)++;
		spec->width = va_arg(ap, int);
		if (spec->width < 0)
		{
			spec->width = ABS(spec->width);
			spec->flag.minus = true;
		}
		if (ft_isdigit(**pp_str))
			spec->width = ft_pr_atoi(pp_str);
	}
}
