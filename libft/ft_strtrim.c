/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:03:48 by lkaser            #+#    #+#             */
/*   Updated: 2017/09/22 12:03:12 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ws(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *str)
{
	int		len;
	char	*trimmed;

	NULL_GUARD(str);
	len = 0;
	while (*str && ws(*str))
		++str;
	len = ft_strlen(str);
	while (ws(str[len - 1]) && len > 0)
		--len;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	trimmed[len--] = '\0';
	while (len >= 0)
	{
		trimmed[len] = str[len];
		--len;
	}
	return (trimmed);
}
