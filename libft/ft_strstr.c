/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:09:17 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/20 08:56:16 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	unsigned i;

	if (!*needle)
		return ((char *)str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] == needle[i])
		{
			if (!needle[i + 1])
				return ((char *)str);
			++i;
		}
		++str;
	}
	return (NULL);
}
