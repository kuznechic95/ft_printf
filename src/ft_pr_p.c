/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:30 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:00:27 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

char	*ft_pr_p(t_spec *spec, va_list ap)
{
	spec->flag.hash = true;
	return (ft_pr_unsigned(spec, ap));
}
