/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:08:47 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/29 12:47:08 by lkaser           ###   ########.fr       */
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
	MATCH(pf.pre_plus && pf.type == t_int && pf.data.i >= 0,
		ft_strprepend("+", out));
	OR(pf.pad_pos && pf.type == t_int && pf.data.i >= 0,
		ft_strprepend(" ", out));
}

void		format_print(t_printf pf, size_t *len)
{
	char *str;

	MATCH(pf.type == t_int, str = FT_ITOA_BASE(pf.data.i, "0123456789"));
	OR(pf.type == t_hex, str = FT_UTOA_BASE(pf.data.ull, "0123456789abcdef"));
	OR(pf.type == t_hex_up, str = FT_UTOA_BASE(pf.data.ull, "0123456789ABCDEF"));
	OR(pf.type == t_octal, str = FT_UTOA_BASE(pf.data.ull, "012345678"));
	OR(pf.type == t_str, str = pf.data.str);
	OR(pf.type == t_char, str = ft_memset(ft_strnew(2), pf.data.c, 1));
	OTHERWISE(str = FT_ITOA_BASE(pf.data.i, "0123456789"));
	handle_flags(pf, &str);
	*len += str ? ft_strlen(str) : 0;
	ft_putstr(str);
	if (pf.type != t_str)
		free(str);
}
