/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:55:46 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:01 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

void		identify_flag(char **p_str, t_flag *flag)
{
	while (**p_str == '0' || **p_str == '-' || **p_str == '+' || \
			**p_str == ' ' || **p_str == '#')
	{
		if (**p_str == '0')
			flag->zero = true;
		else if (**p_str == '-')
			flag->minus = true;
		else if (**p_str == '+')
			flag->plus = true;
		else if (**p_str == ' ')
			flag->space = true;
		else if (**p_str == '#')
			flag->hash = true;
		(*p_str)++;
	}
}
