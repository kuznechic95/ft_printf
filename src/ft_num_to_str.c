/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:50:50 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:59:40 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void	ft_digit_to_str(uintmax_t digit, t_bool up, char **p_str)
{
	if (digit >= 10)
		**p_str = (char)(((up) ? 'A' : 'a') + (digit - 10));
	else
		**p_str = digit + '0';
	(*p_str)++;
}

static void	ft_num_str_base(uintmax_t num, int base, t_bool up, char **p_str)
{
	if (num)
	{
		ft_num_str_base(num / base, base, up, p_str);
		ft_digit_to_str(num % base, up, p_str);
	}
}

void		ft_u_num_to_str(t_u_num *u_num, t_bool up, char **p_str)
{
	if (!(u_num->num))
		*(*p_str)++ = '0';
	else
		ft_num_str_base(u_num->num, u_num->base, up, p_str);
}

void		ft_s_num_to_str(t_s_num *s_num, t_bool up, char **p_str)
{
	if (!(s_num->num))
	{
		**p_str = '0';
		(*p_str)++;
	}
	else
		ft_num_str_base(ABS(s_num->num), s_num->base, up, p_str);
}
