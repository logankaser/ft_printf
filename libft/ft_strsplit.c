/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:30:04 by lkaser            #+#    #+#             */
/*   Updated: 2017/10/12 15:46:50 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_size(const char *chr, char d)
{
	int size;

	size = 0;
	while (*chr && *chr != d)
	{
		++size;
		++chr;
	}
	return (size);
}

static size_t	num_words(const char *str, char d)
{
	size_t num;

	num = 0;
	while (*str)
	{
		if (*str != d && (*(str + 1) == d || *(str + 1) == '\0'))
			++num;
		++str;
	}
	return (num);
}

char			**ft_strsplit(const char *str, const char d)
{
	char		**split_words;
	size_t		size;
	size_t		w_size;
	unsigned	w;
	unsigned	chr;

	NULL_GUARD(str);
	size = num_words(str, d) + 1;
	NULL_GUARD(split_words = (char **)malloc(sizeof(char*) * size));
	w = 0;
	while (w < size)
	{
		while (*str == d)
			++str;
		w_size = word_size(str, d);
		split_words[w] = (char *)malloc(w_size);
		NULL_GUARD(split_words[w]);
		split_words[w][w_size] = '\0';
		chr = 0;
		while (chr < w_size)
			split_words[w][chr++] = *str++;
		++w;
	}
	split_words[size - 1] = 0;
	return (split_words);
}
