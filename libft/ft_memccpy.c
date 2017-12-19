/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:45:43 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/19 21:10:22 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned		i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dst;
	while (i < n)
	{
		d[i] = *((unsigned char *)src + i);
		if (d[i] == (unsigned char)c)
			return (dst + i + 1);
		++i;
	}
	return (NULL);
}
