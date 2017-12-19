/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:46:49 by lkaser            #+#    #+#             */
/*   Updated: 2017/10/10 18:14:43 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*fn)(char))
{
	char		*new;
	unsigned	i;

	NULL_GUARD((str && fn));
	i = ft_strlen(str);
	new = malloc(i + 1);
	NULL_GUARD(new);
	new[i] = '\0';
	i = 0;
	while (*str)
		new[i++] = fn(*str++);
	return (new);
}
