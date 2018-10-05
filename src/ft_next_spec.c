/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:41:58 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:59:30 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void		max_get_width(char **p_str, t_spec *spec, va_list ap)
{
	int			temp;

	temp = spec->width;
	identify_width(p_str, spec, ap);
	if (spec->width < temp)
		spec->width = temp;
}

static void		max_get_precision(char **p_str, t_spec *spec, va_list ap)
{
	int	temp;

	temp = spec->precision;
	identify_prec(p_str, spec, ap);
	if (spec->precision < temp)
		spec->precision = temp;
	if (**p_str == '.')
		spec->precision = 0;
}

int				inc_pointer(char **format)
{
	if (**format != '\0')
	{
		(*format)++;
		return (1);
	}
	else
		return (0);
}

void			ft_next_spec(t_spec *spec, char **p_str, va_list ap)
{
	if (**p_str == '%')
		inc_pointer(p_str);
	while (true)
	{
		if (**p_str && ft_strchr("#0-+ /=\'^_", **p_str))
			identify_flag(p_str, &(spec->flag));
		else if (**p_str && (ft_isdigit(**p_str) || (int)**p_str == '*'))
			max_get_width(p_str, spec, ap);
		else if (**p_str && **p_str == '.')
			max_get_precision(p_str, spec, ap);
		else if (**p_str && ft_strchr("hljzL", **p_str))
			get_length(p_str, &(spec->length));
		else if (!(**p_str) || ft_isalpha(**p_str) || (**p_str) == '%')
			break ;
		else
			NULL_ERROR_BREAK(inc_pointer(p_str));
	}
}
