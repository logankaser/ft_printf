/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:55:40 by lkaser            #+#    #+#             */
/*   Updated: 2017/10/25 21:33:15 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*copy;
	unsigned	len;
	unsigned	i;

	len = ft_strlen(str);
	NULL_GUARD(copy = malloc(len + 1));
	i = 0;
	while (i < len)
		copy[i++] = *str++;
	copy[i] = '\0';
	return (copy);
}
