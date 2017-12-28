/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:38:16 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/21 21:16:43 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned long long nbr, char *base_str, unsigned base)
{
	unsigned long long	n;
	unsigned						digits;
	char								*str;

	digits = 1;
	n = nbr;
	while (n)
	{
		n /= base;
		++digits;
	}
	NULL_GUARD(str = malloc(digits + 1));
	str[digits] = '\0';
	while (digits)
	{
		--digits;
		str[digits] = base_str[nbr % base];
		nbr /= base;
	}
	return (str);
}