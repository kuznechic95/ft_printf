/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:51:26 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:53 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void			read_more_length(char **pp_str, t_length *length)
{
	if ((**pp_str == 'l') || (**pp_str == 'h') || (**pp_str == 'j') \
	|| (**pp_str == 'z'))
		get_length(pp_str, length);
}

void				get_length(char **pp_str, t_length *length)
{
	if (**pp_str == 'l' && (*pp_str)++)
	{
		if ((**pp_str == 'l') && (*pp_str)++)
			length->ll = true;
		else
			length->l = true;
	}
	else if (**pp_str == 'h' && (*pp_str)++)
	{
		if ((**pp_str == 'h') && (*pp_str)++)
			length->hh = true;
		else
			length->h = true;
	}
	else if ((**pp_str == 'j') && (*pp_str)++)
		length->j = true;
	else if ((**pp_str == 'z') && (*pp_str)++)
		length->z = true;
	read_more_length(pp_str, length);
}
