/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 20:38:49 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/01 16:25:08 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *a, char const *b)
{
	char		*c;
	unsigned	len;

	len = (a ? ft_strlen(a) : 0) + (b ? ft_strlen(b) : 0);
	NULL_GUARD(c = malloc(len + 1));
	c[len] = '\0';
	if (a)
		while (*a)
			*c++ = *a++;
	if (b)
		while (*b)
			*c++ = *b++;
	return (c - len);
}
