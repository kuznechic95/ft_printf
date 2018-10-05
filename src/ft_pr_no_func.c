/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_no_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:42:07 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:15 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

char		sltp(int *number, int n_to_compare)
{
	if (*number > n_to_compare)
	{
		(*number)--;
		return (1);
	}
	else
		return (0);
}

char		*ft_pr_no_function(t_spec *spec)
{
	char	c;
	char	*p_str;
	char	*temp_p_str;

	spec->sltprint = spec->width - 1;
	spec->width = MAX(spec->width, 1);
	MALLOC_ERROR((p_str = ft_strnew(spec->width)));
	temp_p_str = p_str;
	c = (!(spec->flag.zero)) ? ' ' : '0';
	while (!(spec->flag.minus) && sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	*temp_p_str++ = spec->type;
	while (sltp(&spec->sltprint, 0))
		*temp_p_str++ = c;
	return (p_str);
}
