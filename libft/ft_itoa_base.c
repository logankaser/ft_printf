/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:38:16 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/21 21:16:43 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned	digits(long long nbr)
{
	unsigned long long	len;

	len = 1 + nbr < 0;
	while (nbr)
	{
		nbr /= 10;
		++len;
	}
	return (len);
}

static void		fill_str(long long nbr, char *str, unsigned *i)
{
	if (nbr >= 10 || nbr <= -10)
	{
		fill_str(nbr / 10, str, i);
		fill_str(nbr % 10, str, i);
	}
	else
		str[(*i)++] = '0' + (nbr < 0 ? -nbr : nbr);
}

char			*ft_itoa_base(long long nbr, base)
{
	unsigned long long 	len;
	char				*out;
	unsigned long long	i;

	len = digits(nbr);
	NULL_GUARD(out = malloc(len + 1));
	i = 0;
	if (nbr < 0)
		out[i++] = '-';
	fill_str(nbr, out, &i);
	out[len] = '\0';
	return (out);
}
