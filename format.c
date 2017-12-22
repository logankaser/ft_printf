/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:08:47 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/21 21:09:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flags(t_printf pf, char **out)
{
	if (pf.pre)
	{
		MATCH(pf.type == t_octal, ft_strprepend("0", out));
		OR(pf.type == t_hex, ft_strprepend("0x", out));
		OR(pf.type == t_hex_up, ft_strprepend("0X", out));
	}
	MATCH(pf.pre_plus && pf.type == t_int && pf.data.t_int >= 0,
		ft_strprepend("+", out));
	OR(pf.pad_pos && pf.type == t_int && pf.data.t_int >= 0,
		ft_strprepend(" ", out));
}

void		format_print(t_printf pf, size_t *len)
{
	char *str;

	str = ft_itoa(pf.data.t_int);
	handle_flags(pf, &str);
	*len += str ? ft_strlen(str) : 0;
	ft_putstr(str);
	free(str);
}
