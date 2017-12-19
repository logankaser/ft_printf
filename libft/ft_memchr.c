/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:45:43 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/19 21:09:28 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned			i;
	const unsigned char	*s;

	i = 0;
	s = (const unsigned char *)src;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return ((void *)src + i);
		++i;
	}
	return (NULL);
}
