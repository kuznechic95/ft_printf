/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:36:29 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:59:56 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

void			ft_del_for_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void		ft_lst_print_stdout(t_list *top)
{
	while (top)
	{
		write(1, (char *)top->content, top->content_size);
		top = top->next;
	}
}

static void		ft_final_str_formation(char *p_str, t_list *top)
{
	char		*tmp_p_str;

	while (top)
	{
		tmp_p_str = top->content;
		while (top->content_size)
		{
			*p_str++ = *tmp_p_str++;
			top->content_size--;
		}
		top = top->next;
	}
}

void			ft_pr_lst(int size, t_list **top)
{
	char		*p_str;

	if ((p_str = ft_strnew(size)) == NULL)
		ft_lst_print_stdout(*top);
	else
	{
		ft_final_str_formation(p_str, *top);
		write(1, p_str, size);
		ft_strdel(&p_str);
	}
	ft_lstdel(top, &ft_del_for_lst);
}
