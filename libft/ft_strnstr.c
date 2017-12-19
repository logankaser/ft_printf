/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:09:17 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/20 09:34:10 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t size)
{
	unsigned i;
	unsigned k;

	if (!*needle)
		return ((char *)str);
	k = 0;
	while (str[k] && k < size)
	{
		i = 0;
		while (str[k + i] && str[k + i] == needle[i] && k + i < size)
		{
			if (!needle[i + 1])
				return ((char *)str + k);
			++i;
		}
		++k;
	}
	return (NULL);
}
