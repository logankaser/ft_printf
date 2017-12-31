/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:37:38 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/30 16:25:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*wchar_utf8(wchar_t wc)
{
	char	*utf8;

	NULL_GUARD(utf8 = ft_strnew(5));
	if (wc <= 0x7f)
		utf8[0] = (char)wc;
	else if (wc <= 0x7ff)
	{
		utf8[0] = ((wc >> 6) | 0xC0);
		utf8[1] = ((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0xffff)
	{
		utf8[0] = (((wc >> 12)) | 0xE0);
		utf8[1] = (((wc >> 6) & 0x3F) | 0x80);
		utf8[2] = ((wc & 0x3F) | 0x80);
	}
	else if (wc <= 0x10ffff)
	{
		utf8[0] = (((wc >> 18)) | 0xF0);
		utf8[1] = (((wc >> 12) & 0x3F) | 0x80);
		utf8[2] = (((wc >> 6) & 0x3F) | 0x80);
		utf8[3] = ((wc & 0x3F) | 0x80);
	}
	return (utf8);
}

char		*ft_wchar_utf8(wchar_t *ws)
{
	char *out;

	NULL_GUARD(out = ft_strnew(1));
	while (*ws)
		ft_strappend(&out, wchar_utf8(*ws++));
	return (out);
}
