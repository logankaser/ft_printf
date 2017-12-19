/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:31:30 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/19 21:06:32 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t size)
{
	unsigned i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < size)
		dst[i++] = '\0';
	return (dst);
}
