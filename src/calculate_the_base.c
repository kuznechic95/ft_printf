/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_the_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:51:20 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:58:11 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

int			calculate_the_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (HEX);
	else if (c == 'o' || c == 'O')
		return (OCT);
	else if (c == 'b' || c == 'B')
		return (BIN);
	else
		return (DEC);
}
