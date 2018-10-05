/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:50:25 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:01:36 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

void			ft_lst_add_back(t_list **top, t_list *elem)
{
	t_list		*p;

	if (top && *top)
	{
		p = *top;
		while (p->next)
			p = p->next;
		p->next = elem;
	}
	else
		*top = elem;
}

static	void	ft_inc_size(char **format, int *size, char **str)
{
	if (**format && **format != '%')
	{
		*(*str)++ = *(*format)++;
		(*size)++;
	}
}

void			ft_str_append(char **dest, char *src)
{
	while (*src)
		*(*dest)++ = *src++;
}

void			ft_read(char **format, int *size, t_list **top)
{
	char		*temp_p_str;
	t_list		*elem;
	char		*p;

	p = ft_strchr(*format, '%');
	MALLOC_ERROR((temp_p_str = ft_strnew(((p) ? \
		(p - *format) : ft_strlen(*format)) * sizeof(char) * 5)));
	p = temp_p_str;
	while (**format)
	{
		if (**format == '%')
		{
			if (!(*(*format + 1) == '}'))
				break ;
			else
				(*format)++;
		}
		if (**format == '{')
			ft_colour(format, &temp_p_str, size);
		ft_inc_size(format, size, &temp_p_str);
	}
	MALLOC_ERROR((elem = ft_lst_new_elem(p, (temp_p_str - p))));
	ft_lst_add_back(top, elem);
}
