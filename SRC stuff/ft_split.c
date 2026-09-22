/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:11:46 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/22 10:18:24 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

//charset set of characters as separators
//return 1 if character is within charset, else 0
static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (!is_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

static int	count_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	return (i);
}

static char	*add_word(char *str, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		word_len;

	result = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str[i], charset))
			i++;
		word_len = count_word_len(str + i, charset);
		if (word_len)
		{
			result[j] = add_word(str + i, word_len);
			j++;
		}
		i += word_len;
		word_len = 0;
	}
	result[j] = 0;
	return (result);
}
