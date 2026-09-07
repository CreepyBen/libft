/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:54:44 by ben               #+#    #+#             */
/*   Updated: 2026/09/07 13:01:32 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t word_len(char const *s, char c, size_t start)
{
	size_t	pos;
	size_t	len;

	pos = start;
	while (s[pos] && s[pos] != c)
		pos++;
	len = pos - start;
	return (len);
}

static void	free_fail(char **array, size_t count)
{
	size_t	i;
	
	i = 0;
	while(i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char **fill_words(char **array, char const *s, char c)
{
	size_t	pos;
	size_t	word_index;
	size_t	start;
	size_t	len;

	pos = 0;
	word_index = 0;
	while(s[pos])
	{
		if(s[pos] != c && (pos == 0 || s[pos - 1] == c))
		{
			start = pos;
			len = word_len(s, c, start);
			array[word_index] = ft_substr(s, start, len);
			if(array[word_index] == NULL)
			{
				free_fail(array, word_index);
				return (NULL);
			}
			word_index++;
			pos += len;
		}
		else
			pos++;
	}
	array[word_index] = NULL;
	return(array);
}

char **ft_split(char const *s, char c)
{
	size_t	words;
	char **array;

	words = count_words(s,c);
	array = malloc(sizeof(char *) * (words + 1));
	if(array == NULL)
		return NULL;
	array = fill_words(array, s, c);
	if(array == NULL)
		return NULL;
	return array;
}