/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:42:21 by okuzniet          #+#    #+#             */
/*   Updated: 2018/10/05 20:59:01 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printflib.h"

static void	ft_color_key_value_set2(char **pp_str, char **key, char **value)
{
	if (!ft_strncmp("{RESET}", *pp_str, ft_strlen("{RESET}")))
	{
		*key = ft_strdup("{RESET}");
		*value = ft_strdup("\x1b[0m");
	}
	else if (!ft_strncmp("{BLACK}", *pp_str, ft_strlen("{BLACK}")))
	{
		*key = ft_strdup("{BLACK}");
		*value = ft_strdup("\x1b[30m");
	}
	else if (!ft_strncmp("{RED}", *pp_str, ft_strlen("{RED}")))
	{
		*key = ft_strdup("{RED}");
		*value = ft_strdup("\x1b[31m");
	}
	else if (!ft_strncmp("{GREEN}", *pp_str, ft_strlen("{GREEN}")))
	{
		*key = ft_strdup("{GREEN}");
		*value = ft_strdup("\x1b[32m");
	}
	else if (!ft_strncmp("{YELLOW}", *pp_str, ft_strlen("{YELLOW}")))
	{
		*key = ft_strdup("{YELLOW}");
		*value = ft_strdup("\x1b[33m");
	}
}

static void	ft_color_key_value_set1(char **pp_str, char **key, char **value)
{
	if (!ft_strncmp("{BLUE}", *pp_str, ft_strlen("{BLUE}")))
	{
		*key = ft_strdup("{BLUE}");
		*value = ft_strdup("\x1b[34m");
	}
	else if (!ft_strncmp("{MAGENTA}", *pp_str, ft_strlen("{MAGENTA}")))
	{
		*key = ft_strdup("{MAGENTA}");
		*value = ft_strdup("\x1b[35m");
	}
	else if (!ft_strncmp("{CYAN}", *pp_str, ft_strlen("{CYAN}")))
	{
		*key = ft_strdup("{CYAN}");
		*value = ft_strdup("\x1b[36m");
	}
	else if (!ft_strncmp("{WHITE}", *pp_str, ft_strlen("{WHITE}")))
	{
		*key = ft_strdup("{WHITE}");
		*value = ft_strdup("\x1b[37m");
	}
}

void		ft_colour(char **format, char **p_str, int *size)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	ft_color_key_value_set1(format, &key, &value);
	ft_color_key_value_set2(format, &key, &value);
	if (!key || !value)
		return ;
	ft_str_append(p_str, value);
	*format += ft_strlen(key);
	*size += ft_strlen(value);
	ft_strdel(&key);
	ft_strdel(&value);
	return ;
}
