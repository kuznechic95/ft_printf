/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:51:36 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 21:02:40 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

t_list		*ft_lst_new_elem(void *ct, size_t ct_size)
{
	t_list *top;

	top = NULL;
	if ((top = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (ct)
		{
			top->content = ct;
			top->content_size = ct_size;
		}
		else
		{
			top->content = NULL;
			top->content_size = 0;
		}
		top->next = NULL;
	}
	return (top);
}

void		choose_function(char **str, t_spec *p, va_list ap)
{
	if (p->type == 's')
		*str = ft_pr_s(p, ap);
	else if (p->type == 'c')
		*str = ft_pr_c(p, ap);
	else if (p->type == 'S')
		*str = ft_pr_us(p, ap);
	else if (p->type == 'C')
		*str = ft_pr_uc(p, ap);
	else if (p->type == 'd' || p->type == 'i')
		*str = ft_pr_signed(p, ap);
	else if (p->type == 'u' || p->type == 'o' || \
				p->type == 'x' || p->type == 'b')
		*str = ft_pr_unsigned(p, ap);
	else if (p->type == 'p')
		*str = ft_pr_p(p, ap);
	else if (p->type == 'n')
		*str = ft_pr_n(p, ap);
	else if (p->type == '%')
		*str = ft_pr_percent_sign(p, ap);
	else
		*str = ft_pr_no_function(p);
}

int			set_function(t_spec *p, va_list ap, t_list **top, int *size)
{
	t_list	*elem;
	char	*res;

	res = NULL;
	p->sltprint = (p->type == 'n') ? *size : 0;
	choose_function(&res, p, ap);
	if (!res || ft_strequ(res, "MB_CUR_MAX_ERROR"))
		return (-1);
	MALLOC_ERROR((elem = ft_lst_new_elem(res, (p->width))));
	ft_lst_add_back(top, elem);
	return (p->width);
}
