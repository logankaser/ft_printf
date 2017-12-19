/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:38:16 by lkaser            #+#    #+#             */
/*   Updated: 2017/11/08 16:05:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned	digits(int nbr)
{
	unsigned len;

	len = 1 + nbr < 0;
	while (nbr /= 10)
		++len;
	return (len);
}

static void		fill_str(long nbr, char *str, unsigned *i)
{
	if (nbr >= 10 || nbr <= -10)
	{
		fill_str(nbr / 10, str, i);
		fill_str(nbr % 10, str, i);
	}
	else
		str[(*i)++] = '0' + (nbr < 0 ? -nbr : nbr);
}

char			*ft_itoa(long nbr)
{
	unsigned	len;
	char		*out;
	unsigned	i;

	len = digits(nbr);
	NULL_GUARD(out = malloc(len + 1));
	i = 0;
	if (nbr < 0)
		out[i++] = '-';
	fill_str(nbr, out, &i);
	out[len] = '\0';
	return (out);
}
