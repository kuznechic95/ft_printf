/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:50:04 by okuzniet          #+#    #+#             */
/*   Updated: 2017/10/25 19:50:08 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *restrict src, int c, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if ((unsigned char)c == *((unsigned char *)src + i))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
