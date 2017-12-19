/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:48:39 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/19 21:11:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t size)
{
	char		*ch;
	unsigned	i;

	ch = dst;
	i = 0;
	while (*ch)
		++ch;
	while (i < size && src[i])
	{
		ch[i] = src[i];
		++i;
	}
	ch[i] = '\0';
	return (dst);
}
