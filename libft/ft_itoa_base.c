/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:38:16 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/28 19:47:58 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(long long nbr, char *base_str, unsigned base)
{
	long long			n;
	unsigned long	digits;
	char					*str;

	digits = 1 + nbr < 0;
	n = nbr;
	while (n)
	{
		n /= base;
		++digits;
	}
	NULL_GUARD(str = malloc(digits + 1));
	str[digits--] = '\0';
	n = nbr;
	while (digits)
	{
		str[digits] = base_str[nbr < 0 ? (nbr % base) * -1 : nbr % base];
		nbr /= base;
		--digits;
	}
	str[0] = n < 0 ? '-' : base_str[nbr % base];
	return (str);
}
