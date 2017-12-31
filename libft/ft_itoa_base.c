/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:38:16 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/29 17:27:50 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(intmax_t nbr, char *base_str, unsigned base)
{
	intmax_t	n;
	unsigned	digits;
	char		*str;

	digits = (nbr <= 0);
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
