/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:06:03 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/21 13:59:31 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**%[%][flags][width][(dot)precision][length]specifier
**
**Specifiers:
**	c	int converted to char
**	C	int converted to wide char
**	s	string
**	S	wide char string
**	p	pointer
**	di	int, D = ld
**	u	unsigned, U = lu
**	o	unsigned in octal, O = lo
**	x	unsigned in hexadecimal
**	X	unsigned in hexadecimal uppercase
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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

enum					e_type {
	t_char = 1, t_wchar,
	t_str, t_wstr, t_ptr, t_int,
	t_uint, t_octal, t_hex, t_hex_up};

enum					e_length { l_hh = 1, l_h, l_l, l_ll, l_j, l_z };

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
	t_type				arg;
	enum e_type			type;
	enum e_length		len;
	t_bool				pre;
	t_bool				pad_zero;
	t_bool				left_align;
	t_bool				pre_plus;
	t_bool				pad_pos;
	unsigned			width;
	unsigned			prec;
}						t_printf;

unsigned    read_num(char **f);

#endif
