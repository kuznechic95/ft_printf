/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:46:05 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/31 16:46:06 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		free_str_split(char **str2, int i)
{
	int		m;

	m = 0;
	while (m < i)
	{
		free(str2[i]);
		str2[i] = NULL;
	}
}

static char		**split(char const *s, char c, char **str2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			free_str_split(str2, i);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
		i++;
	}
	str2[i] = 0;
	return (str2);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str2;

	if (!s)
		return (NULL);
	if (!(str2 = (char **)malloc(sizeof(*str2) * (ft_countwords(s, c) + 1))))
		return (NULL);
	return (split(s, c, str2));
}

/*
**Prototype
**	char ** ft_strsplit(char const *s, char c);
**Description
**	Allocates (with malloc(3)) and returns an array of “fresh”
**	strings (all ending with ’\0’, including the array itself) obtained
**	by spliting s using the character c as a delimiter.
**	If the allocation fails the function returns NULL.
**	Example: ft_strsplit("*hello*fellow***students*", ’*’) returns
**	the array ["hello", "fellow", "students"].
**Param. #1
**	The string to split.
**Param. #2
**	The delimiter character.
**Return value
**	The array of “fresh” strings result of the split.
**Libc functions
**	malloc(3), free(3)
*/
