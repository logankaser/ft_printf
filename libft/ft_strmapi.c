/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:46:49 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 12:02:58 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*fn)(unsigned, char))
{
	char		*new;
	unsigned	i;

	NULL_GUARD((str && fn));
	i = ft_strlen(str);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (*str)
	{
		new[i] = fn(i, *str);
		++i;
		++str;
	}
	return (new);
}
