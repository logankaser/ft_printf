/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:28:53 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 12:03:26 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned start, size_t len)
{
	char		*sub;
	unsigned	i;

	NULL_GUARD(str);
	sub = (char *)malloc(len + 1);
	NULL_GUARD(sub);
	sub[len] = '\0';
	i = 0;
	str += start;
	while (i < len)
	{
		sub[i] = str[i];
		++i;
	}
	return (sub);
}
