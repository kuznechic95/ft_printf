/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:42:11 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:29 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "../inc/ft_printflib.h"

static int		del_lst(t_list **g_head, t_spec *spec)
{
	ft_memdel((void **)&spec);
	ft_lstdel(g_head, &ft_del_for_lst);
	return (-1);
}

static int		type_read(char **p_str, t_spec *spec, int size, va_list ap)
{
	t_list		*top;
	int			temp;

	size = 0;
	top = NULL;
	while (true)
	{
		make_false(spec);
		ft_read(p_str, &size, &top);
		ft_next_spec(spec, p_str, ap);
		identify_type(**p_str, spec);
		if (spec->type != '\0')
		{
			temp = set_function(spec, ap, &top, &size);
			if (temp >= 0)
				size += temp;
			else
				return (del_lst(&top, spec));
		}
		NULL_ERROR_BREAK(inc_pointer(p_str));
	}
	ft_memdel((void **)&spec);
	ft_pr_lst(size, &top);
	return (size);
}

int				ft_pr(char *format, va_list ap)
{
	int			size;
	t_spec		*spec;

	size = 0;
	MALLOC_ERROR((spec = (t_spec*)malloc(sizeof(t_spec))));
	size = type_read(&format, spec, size, ap);
	return (size);
}

int				ft_printf(const char *format, ...)
{
	int			size;
	va_list		ap;

	size = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	size = ft_pr((char *)format, ap);
	va_end(ap);
	return (size);
}
