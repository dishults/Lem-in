/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:33:09 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:33:10 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char *s, char c)
{
	int		char_to_check;
	int		letter;
	int		words_count;

	char_to_check = 0;
	letter = 0;
	words_count = 0;
	while (s[char_to_check])
	{
		if (s[char_to_check] != c)
		{
			letter++;
			if (letter == 1)
				words_count++;
		}
		else
			letter = 0;
		char_to_check++;
	}
	return (words_count);
}

static int	ft_char_count(char *s, char c, int word_to_check, int *word_start)
{
	int		char_to_check;
	int		letter;
	int		found;
	int		length;

	char_to_check = 0;
	letter = 0;
	found = -1;
	length = 0;
	while (s[char_to_check])
	{
		if (s[char_to_check] != c)
		{
			letter++;
			if (letter == 1)
				if (++found == word_to_check)
					*word_start = char_to_check;
			if (found == word_to_check)
				length++;
		}
		else
			letter = 0;
		char_to_check++;
	}
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word_start;
	int		word_to_check;
	int		words_count;
	char	**copy;
	int		char_count;

	word_start = 0;
	word_to_check = 0;
	words_count = ft_words_count((char *)s, c);
	if (!(copy = malloc(sizeof(char *) * words_count + 1)))
		return (0);
	while (word_to_check < words_count)
	{
		char_count = ft_char_count((char *)s, c, word_to_check, &word_start);
		copy[word_to_check] = ft_strndup((char *)&s[word_start], char_count);
		word_to_check++;
	}
	copy[word_to_check] = NULL;
	return (copy);
}
