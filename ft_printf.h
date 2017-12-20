/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:06:03 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/19 21:43:29 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**%[%][flags][width][(dot)precision][length]specifier
**
**Specifiers:
**	s	string
**	S	wide char string
**	p	pointer
**	di	int, D = ld
**	u	unsigned, U = lu
**	o	unsigned in octal, O = lo
**	x	unsigned in hexadecimal
**	X	unsigned in hexadecimal uppercase
**	cC	char
**
**Flags:
**	#		(o,O) prepend '0', x prepend "0x", X prepend "0X"
**	0		Prepend pad with '0' to width (if specified) for numeric types
**	-		Left align within width (if specified)
**	+		Prepend '+' for positive numeric types
**	(space)	Prepend pad positive numbers with a space
**
**Width:
**	<n>	Minimum of n characters are printed
**	*	(Bonus) Width is an int arg before the specifed arg
**
**Precision:
**	(dot)<n>	(idD, uU, oO, xX) Pad with leading zeros if less than n
**	(dot)*		(Bonus) Precision is an int arg before the specifed arg
**
**Length (Aka cast as this):
**	hh	(idD) char,			(uU, oO, xX) unsigned char
**	h	(idD) short,		(uU, oO, xX) unsigned short
**	l	(idD) long,			(uU, oO, xX) unsigned long
**	ll	(idD) long long,	(uU, oO, xX) unsigned long long
**	j	(idD) intmax_t,		(uU, oO, xX) uintmax_t
**	z	(idD) size_t,		(uU, oO, xX) size_t
**
**Return Value:
**	Length of printed string
**.
*/

#include "libft.h"
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

enum					e_type {
	t_char = 1, t_uchar,
	t_short, t_ushort,
	t_int, t_uint,
	t_str,
	t_long, t_ulong, t_longlong, t_ulonglong,
	t_intmax, t_uintmax,
	t_size_t};

typedef union			u_type
{
	char				t_char;
	unsigned char		t_uchar;
	short				t_short;
	unsigned short		t_ushort;
	int					t_int;
	unsigned			t_uint;
	char				*t_str;
	long				t_long;
	unsigned long		t_ulong;
	long long			t_longlong;
	unsigned long long	t_ulonglong;
	intmax_t			t_intmax;
	intmax_t			t_uintmax;
	size_t				t_size_t;
}						t_type;

typedef struct			s_printf
{
	t_type				type;
	enum e_type			type_tag;
	t_bool				pre;
	t_bool				pad_zero;
	t_bool				left_align;
	t_bool				pre_plus;
	t_bool				pad_pos;
	unsigned			width;
	unsigned			prec;
}						t_printf;

#endif
